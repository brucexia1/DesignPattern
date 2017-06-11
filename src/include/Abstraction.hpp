#pragma once

class AbstractionImp;

//≥ÈœÛ¿‡
class Abstraction
{
public:
	virtual ~Abstraction(void);
	virtual void Operation() = 0;
protected:
	Abstraction(void);
};

class RefinedAbstraction:public Abstraction 
{
public:
	RefinedAbstraction(AbstractionImp* imp);
	~RefinedAbstraction();
	void Operation();
protected:
private:
	AbstractionImp* _imp;
}; 