#include "ClassAdapter.hpp"

#include <iostream>
using namespace std;

ClassTarget::ClassTarget(void) 
{
}
ClassTarget::~ClassTarget(void) 
{
}


ClassAdaptee::ClassAdaptee(void) 
{
}
ClassAdaptee::~ClassAdaptee(void) 
{
} 
void ClassAdaptee::SpecificRequest() 
{
	cout<<"ClassAdaptee::SpecificRequest"<<endl; 
}


ClassAdapter::ClassAdapter(void) 
{ 
} 
ClassAdapter::~ClassAdapter(void) 
{ 
} 
void ClassAdapter::Request() 
{ 
	this->SpecificRequest(); 
}

