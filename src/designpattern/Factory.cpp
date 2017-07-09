#include "Factory.hpp"
#include "Product.hpp"

#include <iostream>
using namespace std;

FactoryRed::FactoryRed() 
{
    cout<<"enter FactoryRed"<<endl;
} 
FactoryRed::~FactoryRed() 
{
    cout<<"leave FactoryRed"<<endl;
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
    cout<<"enter FactoryGreen"<<endl;
}
FactoryGreen::~FactoryGreen() 
{
    cout<<"leave FactoryGreen"<<endl;
}
AbstractProductPen* FactoryGreen::CreateProductPen() 
{
	return new ProductPenGreen();
}
AbstractProductBook* FactoryGreen::CreateProductBook()
{
	return new ProductBookGreen();
}
