#pragma once

// µœ÷¿‡
class AbstractionImp
{
public:
	virtual ~AbstractionImp(void);
	virtual void Operation() = 0;
protected:
	AbstractionImp(void);
};

class ConcreteAbstractionImpA:public AbstractionImp 
{
public:
	ConcreteAbstractionImpA();
	~ConcreteAbstractionImpA();
	virtual void Operation();
};
class ConcreteAbstractionImpB:public AbstractionImp 
{
public:
	ConcreteAbstractionImpB();
	~ConcreteAbstractionImpB();
	virtual void Operation();
};
