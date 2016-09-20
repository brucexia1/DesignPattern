#include "Abstraction.h"
#include "AbstractionImp.h"

#include <iostream>
using namespace std;

Abstraction::Abstraction(void)
{
}
Abstraction::~Abstraction(void)
{
}


RefinedAbstraction::RefinedAbstraction(AbstractionImp* imp)
{
	_imp = imp;
}

RefinedAbstraction::~RefinedAbstraction()
{
}
void RefinedAbstraction::Operation()
{
	_imp->Operation();
}