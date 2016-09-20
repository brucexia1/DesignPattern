#include "Factory.h"
#include "Product.h"

#include <iostream>
using namespace std;

AbstractFactory::AbstractFactory(void)
{
}
AbstractFactory::~AbstractFactory(void)
{
}


FactoryRed::FactoryRed() 
{
	cout<<"FactoryRed....."<<endl; 
} 
FactoryRed::~FactoryRed() 
{
}
AbstractProductPen* FactoryRed::CreateProductPen() 
{
	return new ProductPenRed();
}
AbstractProductBook* FactoryRed::CreateProductBook() 
{
	return new ProductBookRed();
}

FactoryGreen::FactoryGreen() 
{
	cout<<"FactoryGreen....."<<endl; 
}
FactoryGreen::~FactoryGreen() 
{
}
AbstractProductPen* FactoryGreen::CreateProductPen() 
{
	return new ProductPenGreen();
}
AbstractProductBook* FactoryGreen::CreateProductBook()
{
	return new ProductBookGreen();
}
