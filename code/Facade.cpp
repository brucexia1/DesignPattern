#include "Facade.h"

#include <iostream>
using namespace std;

Subsystem1::Subsystem1() 
{ 
} 
Subsystem1::~Subsystem1() 
{ 
} 
void Subsystem1::Operation() 
{ 
	cout<<"Subsystem1 operation.."<<endl; 
}


Subsystem2::Subsystem2() 
{ 
} 
Subsystem2::~Subsystem2() 
{ 
} 
void Subsystem2::Operation() 
{ 
	cout<<"Subsystem2 operation.."<<endl; 
}


Facade::Facade(void)
{
	m_subs1 = new Subsystem1();
	m_subs2 = new Subsystem2();
}
Facade::~Facade(void)
{
	delete m_subs1;
	delete m_subs2;
}
void Facade::OperationWrapper() 
{
	m_subs1->Operation();
	m_subs2->Operation();
}