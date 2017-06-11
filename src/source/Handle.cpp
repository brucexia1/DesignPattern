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
		cout<<"ConcreteHandleA  �ҰѴ���Ȩ����̽ڵ�....."<<endl; 
		GetSuccessor()->HandleRequest(); 
	} 
	else 
	{ 
		cout<<"ConcreteHandleA  û�к���ˣ��ұ����Լ�����...."<<endl; 
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
		cout<<"ConcreteHandleB  �ҰѴ���Ȩ����̽ڵ�....."<<endl; 
		GetSuccessor()->HandleRequest(); 
	}
	else 
	{
		cout<<"ConcreteHandleB  û�к���ˣ��ұ����Լ�����...."<<endl; 
	}
} 
