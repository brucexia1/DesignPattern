#include "Proxy.hpp"

#include <iostream>
using namespace std;

Subject::Subject() 
{
} 
Subject::~Subject() 
{
}


ConcreteSubject::ConcreteSubject() 
{
} 
ConcreteSubject::~ConcreteSubject() 
{
} 
void ConcreteSubject::Request() 
{
	cout<<"ConcreteSubject......request...."<<endl; 
}


Proxy::Proxy(void) : m_sub(NULL)
{
}
Proxy::~Proxy(void)
{
	if( NULL != m_sub){
		delete m_sub;
		m_sub = NULL;
	}
}
void Proxy::DoSomething1()
{
    cout << "Proxy::DoSomething1" << endl;
}

void Proxy::DoSomething2()
{
   cout << "Proxy::DoSomething2" << endl;
}

void Proxy::Request()
{
	if(NULL == m_sub){
        m_sub = new ConcreteSubject();
    }
    DoSomething1();		//��ʾ���⸽�ӵĲ��� 
    m_sub->Request();	//�����ʵ�������
    DoSomething2();		//��ʾ���⸽�ӵĲ���
}
