#include "Decorator.hpp"
#include <iostream>
using namespace std;


Component::Component() 
{
}
Component::~Component() 
{
} 


ConcreteComponent::ConcreteComponent() 
{
} 
ConcreteComponent::~ConcreteComponent() 
{
} 
void ConcreteComponent::Operation() 
{
	cout<<"ConcreteComponent operation..."<<endl;
}

Decorator::Decorator(Component* com) 
{
	this->_com = com; 
}
Decorator::~Decorator() 
{
}
void Decorator::Operation() 
{
}


ConcreteDecorator::ConcreteDecorator(Component* com):Decorator(com) 
{
}
ConcreteDecorator::~ConcreteDecorator() 
{
}
void ConcreteDecorator::AddedBehavior() 
{
	cout<<"ConcreteDecorator::AddedBehacior...."<<endl; 
}
void ConcreteDecorator::Operation() 
{
	_com->Operation(); 
	this->AddedBehavior(); 
}

