#include "Composite.h"


Compt::Compt(void)
{
}
Compt::~Compt(void)
{
}






Leaf::Leaf() 
{} 
Leaf::~Leaf() 
{} 
void Leaf::Operation() 
{ 
	cout<<"Leaf operation....."<<endl; 
}






Composite::Composite(void)
{
}

Composite::~Composite(void)
{
}

void Composite::Operation()
{
	vector<Compt*>::iterator comiter = comVec.begin();
	for(;comiter != comVec.end() ; ++comiter)
	{
		(*comiter)->Operation();
	}
}
void Composite::Add(Compt * com)
{
	comVec.push_back(com);
}
void Composite::Remove(Compt * com)
{
	//comVec.erase(com);
}
Compt * Composite::GetChild(int index)
{
	return comVec[index];
}