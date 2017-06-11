#pragma once

class AbstractProductPen;
class AbstractProductBook;

class AbstractFactory
{
public:
	virtual ~AbstractFactory(void) = 0;

	//工厂Factory提供的创建产品对象的接口，接口所在类都是抽象类，具体实现在子类中实现
	virtual AbstractProductPen *CreateProductPen() = 0;
	virtual AbstractProductBook *CreateProductBook() = 0;

protected:
	AbstractFactory(void);
private:
};

class FactoryRed:public AbstractFactory
{
public: 
	~FactoryRed();
	FactoryRed();
 
	AbstractProductPen *CreateProductPen();
	AbstractProductBook *CreateProductBook();
protected: 
private: 
};
class FactoryGreen:public AbstractFactory
{
public: 
	~FactoryGreen(); 
	FactoryGreen(); 

	AbstractProductPen *CreateProductPen();
	AbstractProductBook *CreateProductBook();
protected:
private:
};

