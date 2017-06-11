#include "Abstraction.hpp"
#include "AbstractionImp.hpp"

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
