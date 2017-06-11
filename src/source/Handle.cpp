#include "Handle.hpp"

#include <iostream>
using namespace std;

Handle::Handle(void)
{
	_succ = 0;
}
Handle::~Handle(void)
{
}
Handle::Handle(Handle* succ) 
{ 
	_succ = succ; 
}
void Handle::SetSuccessor(Handle* succ) 
{ 
	_succ = succ; 
} 
Handle* Handle::GetSuccessor() 
{ 
	return _succ; 
} 
void Handle::HandleRequest() 
{
}


ConcreteHandleA::ConcreteHandleA() 
{ 
} 
ConcreteHandleA::ConcreteHandleA(Handle* succ):Handle(succ) 
{
} 
ConcreteHandleA::~ConcreteHandleA() 
{ 
}
void ConcreteHandleA::HandleRequest() 
{ 
	if (GetSuccessor() != 0) 
	{
		cout<<"ConcreteHandleA  我把处理权给后继节点....."<<endl; 
		GetSuccessor()->HandleRequest(); 
	} 
	else 
	{ 
		cout<<"ConcreteHandleA  没有后继了，我必须自己处理...."<<endl; 
	} 
}


ConcreteHandleB::ConcreteHandleB() 
{
} 
ConcreteHandleB::ConcreteHandleB(Handle* succ):Handle(succ) 
{
} 
ConcreteHandleB::~ConcreteHandleB() 
{
} 
void ConcreteHandleB::HandleRequest() 
{
	if (GetSuccessor() != 0) 
	{
		cout<<"ConcreteHandleB  我把处理权给后继节点....."<<endl; 
		GetSuccessor()->HandleRequest(); 
	}
	else 
	{
		cout<<"ConcreteHandleB  没有后继了，我必须自己处理...."<<endl; 
	}
} 
