#include "Singleton.hpp"

#include <iostream>
using namespace std;


Singleton *Singleton::pInstance = 0;

Singleton::Singleton(void)
{
    cout<<"enter Singleton"<<endl;
}

Singleton* Singleton::GetInstance()
{
    if (!pInstance){
        cout<<"create Singleton"<<endl;
		pInstance = new Singleton();
	}
	return pInstance;
}
