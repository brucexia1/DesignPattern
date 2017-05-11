#include "Product.hpp"

#include <iostream>
using namespace std;

AbstractProductPen::AbstractProductPen(void)
{
}
AbstractProductPen::~AbstractProductPen(void)
{
}

AbstractProductBook::AbstractProductBook(void)
{
}
AbstractProductBook::~AbstractProductBook(void)
{
}

ProductPenRed::ProductPenRed()
{ 
	cout<<"ProductPenRed...."<<endl; 
}
ProductPenRed::~ProductPenRed()
{
}

ProductPenGreen::~ProductPenGreen()
{
}
ProductPenGreen::ProductPenGreen()
{
	cout<<"ProductPenGreen..."<<endl;
}


ProductBookGreen::~ProductBookGreen()
{
}
ProductBookGreen::ProductBookGreen()
{
	cout<<"ProductBookGreen..."<<endl;
}

ProductBookRed::~ProductBookRed()
{
}
ProductBookRed::ProductBookRed()
{
	cout<<"ProductBookRed..."<<endl;
}
