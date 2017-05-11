#pragma once

#define NULL 0

// ������Proxy��ConcreteSubject�Ĺ��нӿ�,
// �����Ϳ������κ���Ҫʹ�õ�ConcreteSubject�ĵط���ʹ��Proxy.
class Subject 
{
public: 
	virtual ~Subject(); 
	virtual void Request() = 0;
protected: 
	Subject();
};
class ConcreteSubject:public Subject 
{
public:
	ConcreteSubject(); 
	~ConcreteSubject(); 
	void Request();
};

//���������
class Proxy : public Subject
{
public:
	Proxy(void);
	~Proxy(void);
	void DoSomething1();
	virtual void Request();
	void DoSomething2();
private:
	Subject *m_sub;
};

