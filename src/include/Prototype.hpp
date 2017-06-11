#pragma once
class Prototype
{
public:
	virtual ~Prototype(void);
	virtual Prototype *Clone() const = 0;
protected:
	Prototype(void);
};

//������Prototype��ʵ����ӿں���
class ConcretePrototype1:public Prototype
{
public:
    ConcretePrototype1();//���캯��
    ~ConcretePrototype1();//��������
    ConcretePrototype1(const ConcretePrototype1&);//�������캯��
    virtual Prototype* Clone() const;//ʵ�ֻ��ඨ���Clone�ӿڣ��ڲ����ÿ������캯��ʵ�ָ��ƹ���
};

//������Prototype��ʵ����ӿں���
class ConcretePrototype2:public Prototype
{
public:
    ConcretePrototype2();//���캯��
    ~ConcretePrototype2();//��������
    ConcretePrototype2(const ConcretePrototype2&);//�������캯��
    virtual Prototype* Clone() const;//ʵ�ֻ��ඨ���Clone�ӿڣ��ڲ����ÿ������캯��ʵ�ָ��ƹ���
};