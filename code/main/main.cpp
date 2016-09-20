#include "Factory.h"
#include "Product.h"
#include "Singleton.h"
#include "Prototype.h"
#include "Builder.h"

#include "Abstraction.h"
#include "AbstractionImp.h"
#include "ClassAdapter.h"
#include "Adapter.h"
#include "Decorator.h"
#include "Composite.h"
#include "Character.h"
#include "Facade.h"
#include "Proxy.h"

#include "TemplateMethod.h"
#include "Strategy.h"
#include "Observer.h"
#include "Memento.h"
#include "Mediator.h"
#include "Command.h"
#include "Visitor.h"
#include "Handle.h"
#include "Iterator.h"
#include "Interpret.h"


#include <iostream>
using namespace std;

//ProduceProduct����������ͨ������Ĺ�����������Ҫ�����ĸ���Ʒ
//���崴���ĸ���Ʒֱ������ʱ��̬������Ӧ��Ʒ�Ĺ��������������
//������Factory����֪�����崫�����һ�����ֱ࣬������ʱ��̬����
void ProduceProduct(AbstractFactory *fac)
{
	AbstractProductPen *pen = fac->CreateProductPen();
	AbstractProductBook *book = fac->CreateProductBook();
}

int main(int argc, char *argv[])
{
	/************************************************\
	                   ������ģʽ
	\************************************************/
	/***********    Factory Pattern    ************/
	ProduceProduct( new FactoryRed() );
	ProduceProduct( new FactoryGreen() );

	/***********    Singleton Pattern    ************/
	Singleton *sgn = Singleton::GetInstance();

	/***********    Builder Pattern ������ģʽ    ************/
	Director* pDirector = new Director(new ConcreteBuilder1());
    pDirector->Construct();
    pDirector = new Director(new ConcreteBuilder2());
    pDirector->Construct();

	/***********    Prototype Pattern ԭ��ģʽ    ************/
    /*1����ԭ��ʵ��p1ָ���������������ConcretePrototype1 */
    Prototype* p1 = new ConcretePrototype1();
    /*2��ͨ��������Щԭ�ʹ����µĶ��� */
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


	/************************************************\
	                    �ṹ��ģʽ
	\************************************************/
	/***********    Bridge Pattern�Ž�ģʽ��ʹ����Ϸ�ʽ�������ʵ�ֳ��׽��    ************/
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

	/***********    ��ģʽ��������ģʽ(Adapter Pattern)    ************/
	ClassTarget* clsadt = new ClassAdapter();
	clsadt->Request();
	delete clsadt;
	clsadt = NULL;

	/***********   ����ģʽ��������ģʽ(Adapter Pattern)   ************/
	Adaptee* ade = new Adaptee; 
    Target* adt = new Adapter(ade); 
    adt->Request();
	delete ade;
	delete adt;
	ade = NULL;
	adt = NULL;

	/***********    װ��ģʽ��Decorator Pattern��    ************/
	Component* cp = new ConcreteComponent();
	Decorator* dec =  new ConcreteDecorator(cp);
	dec->Operation();

	/***********    ���ģʽ��Composite Pattern��    ************/
	Leaf* l = new Leaf(); 
	l->Operation(); 
	Composite* com = new Composite(); 
	com->Add(l); 
	com->Operation(); 
	Compt* ll = com->GetChild(0); 
	ll->Operation();

	/***********    ��Ԫģʽ��Flyweight Pattern��    ************/
	CharacterFactory* pFactory = new CharacterFactory;  
    //����״̬ �洢����Ԫ�����ڲ����Ҳ����滷���ı���ı�  
    Character* ch1 = pFactory->GetCharacter('A');  
    ch1->Display();  
    //����״̬ �ͻ��˱���  
    Character* ch2 = pFactory->GetCharacter('B');  
    ch2->SetSize(500, 800);  
    ch2->Display(); 

	/***********    ���ģʽ��Facade Pattern��    ************/
	Facade *f = new Facade();
	f->OperationWrapper();

	/***********    ����ģʽ��Proxy Pattern��    ************/
	Proxy* proxy = new Proxy(); 
	proxy->Request();


	/************************************************\
	                    ��Ϊ��ģʽ
	\************************************************/
	/***********    ģ��ģʽ��Template Pattern��    ************/
    AbstractClass* pAbstract = new ConcreteClassA();
    pAbstract->TemplateMethod();

    pAbstract = new ConcreteClassB();
    pAbstract->TemplateMethod();

	/***********    ����ģʽ��Strategy Pattern��    ************/
	Strategy* pStr = new ConcreteStrategyA();
    Context* pcon = new Context(pStr);
    pcon->DoAction();

    pStr = new ConcreteStrategyB();
    pcon = new Context(pStr);
    pcon->DoAction();

	/***********    ״̬ģʽ��State Pattern��    ************/


	/***********    �۲���ģʽ��Observer Pattern��    ************/
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

	/***********    ����¼ģʽ(Memento Pattern)    ************/
	//��ʼ������״̬Ϊ��Old��
    Originator* o = new Originator("Old");
    o->show();

    //����������Memento
    Caretaker* pTaker = new Caretaker();
    pTaker->SetMemento(o->CreateMemento());

    //�ı�״̬
    o->SetState("New");
    o->show();

    //�ָ�״̬
    o->RestoreToMemento(pTaker->GetMemento());
    o->show();

	/***********    �н���ģʽ��Mediator Pattern��    ************/
	ConcreteMediator* pMediator = new ConcreteMediator();
    Colleage* pcg1 = new ConcreteColleageA(pMediator);
    Colleage* pcg2 = new ConcreteColleageB(pMediator);

    pMediator->SetColleageA(pcg1);
    pMediator->SetColleageB(pcg2);

    pcg1->SendMsg("xxx");
    pcg2->SendMsg("ooo");


	/***********    ����ģʽ��Command Pattern��    ************/
	//���������������pCmd���趨���Ľ�����pRev
    Receiver* pRev = new Receiver();
    Command* pCmd = new ConcreteCommandA(pRev);
    //���������
    Invoker* pInv = new Invoker(pCmd);
    pInv->Invoke();

	//pCmd = new ConcreteCommandB<Receiver>(pRev, &Receiver::Action);
	//pInv = new Invoker(pCmd);
 //   pInv->Invoke();


	/***********    ������ģʽ��Visitor Pattern��    ************/
	Visitor *visitor = new ConcreteVisitorA();
	Element *elm = new ConcreteElementA();
	elm->Accept(visitor);


	/***********    ������ģʽ��Chain of Responsibility Pattern��    ************/
	Handle* h1 = new ConcreteHandleA(); 
	Handle* h2 = new ConcreteHandleB();
	h1->SetSuccessor(h2);
	h1->HandleRequest();

	/***********    ������ģʽ��Iterator Pattern��    ************/
	Aggregate* ag =  new ConcreteAggregate();
	Iterator* it = new ConcreteIterator(ag);
	for (; !(it->IsDone()) ; it->Next())
	{
		cout<<it->CurrentItem()<<endl;
	}

	/***********    ������ģʽ��Interpreter Pattern��    ************/
	ContextIpt* c = new ContextIpt(); 
	AbstractExpression* te  = new TerminalExpression("hello"); 
	AbstractExpression*  nte  =  new NonterminalExpression(te,2); 
	nte->Interpret(*c);

	return 0;
}

