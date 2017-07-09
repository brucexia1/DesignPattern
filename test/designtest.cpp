#include <gtest/gtest.h>

#include "Factory.hpp"
#include "Product.hpp"
#include "Singleton.hpp"
#include "Prototype.hpp"
#include "Builder.hpp"

#include "Abstraction.hpp"
#include "AbstractionImp.hpp"
#include "ClassAdapter.hpp"
#include "Adapter.hpp"
#include "Decorator.hpp"
#include "Composite.hpp"
#include "Character.hpp"
#include "Facade.hpp"
#include "Proxy.hpp"

#include "TemplateMethod.hpp"
#include "Strategy.hpp"
#include "Observer.hpp"
#include "Memento.hpp"
#include "Mediator.hpp"
#include "Command.hpp"
#include "Visitor.hpp"
#include "Handle.hpp"
#include "Iterator.hpp"
#include "Interpret.hpp"


#include <iostream>
using namespace std;

/*
 * ProduceProduct函数并不能通过传输的工厂参数具体要创建哪个产品
 * 具体创建哪个产品直到运行时动态传入相应产品的工厂类对象来生产
 * 即父类Factory并不知道具体传入的哪一个子类，直到运行时动态决定
 */
void ProduceProduct(AbstractFactory *fac)
{
    AbstractProductPen *pen = fac->CreateProductPen();
    AbstractProductBook *book = fac->CreateProductBook();
    delete pen;
    delete book;
}

TEST(designtest, create_pattern)
{
    /************************************************\
                       创建型模式
    \************************************************/
    /***********    Factory Pattern    ************/
    FactoryRed *fr = new FactoryRed();
    FactoryGreen *fg = new FactoryGreen();
    ProduceProduct( fr );
    ProduceProduct( fg );
    delete fr;
    delete fg;

    /***********    Singleton Pattern    ************/
    Singleton *sgn = Singleton::GetInstance();

    /***********    Builder Pattern 生成器模式    ************/
    Director* pDirector = new Director(new ConcreteBuilder1());
    pDirector->Construct();
    pDirector = new Director(new ConcreteBuilder2());
    pDirector->Construct();

    /***********    Prototype Pattern 原型模式    ************/
    /*1、用原型实例p1指定创建对象的种类ConcretePrototype1 */
    Prototype* p1 = new ConcretePrototype1();
    /*2、通过拷贝这些原型创建新的对象 */
    Prototype* p2 = p1->Clone();
    cout<< "------------------------" << endl;
    Prototype* p3 = new ConcretePrototype2();
    Prototype* p4 = p3->Clone();

    cout<< "------------------------" << endl;
    delete p1;
    delete p2;
    cout<< "------------------------" << endl;
    delete p3;
    delete p4;
}

TEST(designtest, struct_pattern)
{
    /************************************************\
                        结构型模式
    \************************************************/
    /***********    Bridge Pattern桥接模式（使用组合方式将抽象和实现彻底解耦）    ************/
    AbstractionImp *imp = new ConcreteAbstractionImpA();
    Abstraction *abs = new RefinedAbstraction(imp);
    abs->Operation();
    delete imp;
    delete abs;

    imp = new ConcreteAbstractionImpB();
    abs = new RefinedAbstraction(imp);
    abs->Operation();
    delete imp;
    delete abs;
    imp = NULL;
    abs = NULL;

    /***********    类模式的适配器模式(Adapter Pattern)    ************/
    ClassTarget* clsadt = new ClassAdapter();
    clsadt->Request();
    delete clsadt;
    clsadt = NULL;

    /***********   对象模式的适配器模式(Adapter Pattern)   ************/
    Adaptee* ade = new Adaptee;
    Target* adt = new Adapter(ade);
    adt->Request();
    delete ade;
    delete adt;
    ade = NULL;
    adt = NULL;

    /***********    装饰模式（Decorator Pattern）    ************/
    Component* cp = new ConcreteComponent();
    Decorator* dec =  new ConcreteDecorator(cp);
    dec->Operation();

    /***********    组合模式（Composite Pattern）    ************/
    Leaf* l = new Leaf();
    l->Operation();
    Composite* com = new Composite();
    com->Add(l);
    com->Operation();
    Compt* ll = com->GetChild(0);
    ll->Operation();

    /***********    享元模式（Flyweight Pattern）    ************/
    CharacterFactory* pFactory = new CharacterFactory;
    //内蕴状态 存储在享元对象内部并且不会随环境改变而改变
    Character* ch1 = pFactory->GetCharacter('A');
    ch1->Display();
    //外蕴状态 客户端保存
    Character* ch2 = pFactory->GetCharacter('B');
    ch2->SetSize(500, 800);
    ch2->Display();

    /***********    外观模式（Facade Pattern）    ************/
    Facade *f = new Facade();
    f->OperationWrapper();

    /***********    代理模式（Proxy Pattern）    ************/
    Proxy* proxy = new Proxy();
    proxy->Request();
}

TEST(designtest, action_pattern)
{
    /************************************************\
                        行为型模式
    \************************************************/
    /***********    模板模式（Template Pattern）    ************/
    AbstractClass* pAbstract = new ConcreteClassA();
    pAbstract->TemplateMethod();

    pAbstract = new ConcreteClassB();
    pAbstract->TemplateMethod();

    /***********    策略模式（Strategy Pattern）    ************/
    Strategy* pStr = new ConcreteStrategyA();
    Context* pcon = new Context(pStr);
    pcon->DoAction();

    pStr = new ConcreteStrategyB();
    pcon = new Context(pStr);
    pcon->DoAction();

    /***********    状态模式（State Pattern）    ************/


    /***********    观察者模式（Observer Pattern）    ************/
    Observer* ps1 = new ConcreteObserverA();
    Observer* ps2 = new ConcreteObserverB();
    Observer* ps3 = new ConcreteObserverA();

    CSubject* pSubject = new ConcreteCSubjectA();
    pSubject->Attach(ps1);
    pSubject->Attach(ps2);
    pSubject->Attach(ps3);

    pSubject->SetState("old");
    pSubject->Notify();
    pSubject->SetState("new");
    pSubject->Detach(ps3);
    pSubject->Notify();

    /***********    备忘录模式(Memento Pattern)    ************/
    //初始化对象，状态为“Old”
    Originator* o = new Originator("Old");
    o->show();

    //建立并保存Memento
    Caretaker* pTaker = new Caretaker();
    pTaker->SetMemento(o->CreateMemento());

    //改变状态
    o->SetState("New");
    o->show();

    //恢复状态
    o->RestoreToMemento(pTaker->GetMemento());
    o->show();

    /***********    中介者模式（Mediator Pattern）    ************/
    ConcreteMediator* pMediator = new ConcreteMediator();
    Colleage* pcg1 = new ConcreteColleageA(pMediator);
    Colleage* pcg2 = new ConcreteColleageB(pMediator);

    pMediator->SetColleageA(pcg1);
    pMediator->SetColleageB(pcg2);

    pcg1->SendMsg("xxx");
    pcg2->SendMsg("ooo");


    /***********    命令模式（Command Pattern）    ************/
    //创建具体命令对象pCmd并设定它的接收者pRev
    Receiver* pRev = new Receiver();
    Command* pCmd = new ConcreteCommandA(pRev);
    //请求绑定命令
    Invoker* pInv = new Invoker(pCmd);
    pInv->Invoke();

    //pCmd = new ConcreteCommandB<Receiver>(pRev, &Receiver::Action);
    //pInv = new Invoker(pCmd);
 //   pInv->Invoke();


    /***********    访问者模式（Visitor Pattern）    ************/
    Visitor *visitor = new ConcreteVisitorA();
    Element *elm = new ConcreteElementA();
    elm->Accept(visitor);


    /***********    责任链模式（Chain of Responsibility Pattern）    ************/
    Handle* h1 = new ConcreteHandleA();
    Handle* h2 = new ConcreteHandleB();
    h1->SetSuccessor(h2);
    h1->HandleRequest();

    /***********    迭代器模式（Iterator Pattern）    ************/
    Aggregate* ag =  new ConcreteAggregate();
    Iterator* it = new ConcreteIterator(ag);
    for (; !(it->IsDone()) ; it->Next())
    {
        cout<<it->CurrentItem()<<endl;
    }

    /***********    解释器模式（Interpreter Pattern）    ************/
    ContextIpt* c = new ContextIpt();
    AbstractExpression* te  = new TerminalExpression("hello");
    AbstractExpression*  nte  =  new NonterminalExpression(te,2);
    nte->Interpret(*c);
}
