#pragma once

#define NULL 0

// 定义了Proxy和ConcreteSubject的公有接口,
// 这样就可以在任何需要使用到ConcreteSubject的地方都使用Proxy.
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

//定义代理类
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

