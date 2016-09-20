#include "Builder.h"

#include <iostream>

BldProduct::~BldProduct()
{}
BldProduct::BldProduct()
{
	m_partA.clear();
	m_partB.clear();
	m_partC.clear();
}

void BldProduct::setPartA(const string& s)
{
    this->m_partA = s;
}
void BldProduct::setPartB(const string& s)
{
    this->m_partB = s;
}
void BldProduct::setPartC(const string& s)
{
    this->m_partC = s;
}







Builder::Builder()
{}
Builder::~Builder()
{}


ConcreteBuilder1::ConcreteBuilder1()
{
    this->m_pProduct = new BldProduct();
    cout<<"Create empty product!"<<endl;
}
void ConcreteBuilder1::BuildPartA()
{
    this->m_pProduct->setPartA("A");
    cout<<"BuildPartA"<<endl;
}
void ConcreteBuilder1::BuildPartB()
{
    this->m_pProduct->setPartB("B");
    cout<<"BuildPartB"<<endl;
}
void ConcreteBuilder1::BuildPartC()
{
    this->m_pProduct->setPartC("C");
    cout<<"BuildPartC"<<endl;
}

BldProduct* ConcreteBuilder1::GetProduct()
{
    return this->m_pProduct;
}

ConcreteBuilder1::~ConcreteBuilder1()
{
    delete this->m_pProduct;
    this->m_pProduct = NULL;
}


ConcreteBuilder2::ConcreteBuilder2()
{
    this->m_pProduct = new BldProduct();
    cout<<"Create empty product!"<<endl;
}
void ConcreteBuilder2::BuildPartA()
{
    this->m_pProduct->setPartA("AAA");
    cout<<"BuildPartAAA"<<endl;
}
void ConcreteBuilder2::BuildPartB()
{
    this->m_pProduct->setPartB("BBB");
    cout<<"BuildPartBBB"<<endl;
}
void ConcreteBuilder2::BuildPartC()
{
    this->m_pProduct->setPartC("CCC");
    cout<<"BuildPartCCC"<<endl;
}
BldProduct* ConcreteBuilder2::GetProduct()
{
    return this->m_pProduct;
}
ConcreteBuilder2::~ConcreteBuilder2()
{
    delete this->m_pProduct;
    this->m_pProduct = NULL;
}




Director::Director(Builder* pBuilder)
{
    this->m_pBuilder = pBuilder;
}
void Director::Construct()
{
    this->m_pBuilder->BuildPartA();
    this->m_pBuilder->BuildPartB();
    this->m_pBuilder->BuildPartC();
}
Director::~Director()
{
    delete this->m_pBuilder;
    this->m_pBuilder = NULL;
}