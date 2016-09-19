#pragma once

class Component 
{
public: 
	virtual ~Component();
	virtual void  Operation() = 0;
protected: 
	Component();
private: 
};

class ConcreteComponent:public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void  Operation();
};

class Decorator : public Component
{
public:
	Decorator(Component *com);
	virtual ~Decorator(void);
	virtual void  Operation() = 0;
protected:
	Component *_com;
};

class ConcreteDecorator:public Decorator 
{
public: 
	ConcreteDecorator(Component* com); 
	~ConcreteDecorator(); 
	void Operation(); 
	void AddedBehavior(); 
}; 
