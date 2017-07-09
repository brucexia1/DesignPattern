#pragma once
#include <iostream>

class Singleton
{
public:
	static Singleton *GetInstance();
    ~Singleton(void) {std::cout<<"leave Singleton"<<std::endl;}

protected:
	
private:
	Singleton(void);
	static Singleton *pInstance;
};

