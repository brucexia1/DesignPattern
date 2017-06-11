#include "Singleton.hpp"

#include <iostream>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

Singleton *Singleton::pInstance = NULL;

Singleton::Singleton(void)
{
	cout<<"Singleton"<<endl;
}

Singleton::~Singleton(void)
{
	if(pInstance){
		delete pInstance;
		pInstance = NULL;
	}
}

Singleton* Singleton::GetInstance()
{
	if (NULL == pInstance){
		pInstance = new Singleton();
	}
	return pInstance;
}
