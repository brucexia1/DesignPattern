#include "Adapter.h"

#include <iostream>
using namespace std;

Target::Target() 
{ 
} 
Target::~Target() 
{ 
}


Adaptee::Adaptee() 
{ 
} 
Adaptee::~Adaptee() 
{ 
}
void Adaptee::SpecificRequest() 
{ 
	cout<<"Adaptee::SpecificRequest"<<endl; 
}


Adapter::Adapter(Adaptee *ade)
{
	this->_ade = ade;
}

Adapter::~Adapter(void)
{
}
void Adapter::Request()
{
	_ade->SpecificRequest();
}