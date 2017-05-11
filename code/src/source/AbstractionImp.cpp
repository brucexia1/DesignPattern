#include "AbstractionImp.hpp"

#include <iostream>
using namespace std;

AbstractionImp::AbstractionImp(void)
{
}
AbstractionImp::~AbstractionImp(void)
{
}


ConcreteAbstractionImpA::ConcreteAbstractionImpA() 
{}
ConcreteAbstractionImpA::~ConcreteAbstractionImpA() 
{}
void ConcreteAbstractionImpA::Operation()
{
	cout<<"ConcreteAbstractionImpA...."<<endl; 
}


ConcreteAbstractionImpB::ConcreteAbstractionImpB() 
{}
ConcreteAbstractionImpB::~ConcreteAbstractionImpB() 
{}
void ConcreteAbstractionImpB::Operation() 
{
	cout<<"ConcreteAbstractionImpB...."<<endl; 
}
