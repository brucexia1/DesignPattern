#pragma once

//����ģ�壬��������һ��ģ�巽����
class AbstractClass
{
public:
    ~AbstractClass();
    //�����ģ�巽�����������߼��ĹǼܣ����߼��������һЩ��Ӧ�ĳ�����������Ƕ��Ƴٵ�������ʵ��
    void TemplateMethod();
    //һЩ������Ϊ���ŵ�������ȥʵ��
    virtual void PrimitiveOperation1()=0;
    virtual void PrimitiveOperation2()=0;
protected:
    AbstractClass();
};


//ʵ�ֻ���������ĳ��󷽷�
class ConcreteClassA : public AbstractClass
{
public:
    ConcreteClassA();
    ~ConcreteClassA();
    //ʵ�ֻ��ඨ��ĳ�����Ϊ
    virtual void PrimitiveOperation1();
    virtual void PrimitiveOperation2();
private:
};

//ʵ�ֻ���������ĳ��󷽷�
class ConcreteClassB : public AbstractClass
{
public:
    ConcreteClassB();
    ~ConcreteClassB();
    //ʵ�ֻ��ඨ��ĳ�����Ϊ
    virtual void PrimitiveOperation1();
    virtual void PrimitiveOperation2();
private:
};



