#pragma once

class AbstractProductPen;
class AbstractProductBook;

class AbstractFactory
{
public:
	virtual ~AbstractFactory(void) = 0;

	//����Factory�ṩ�Ĵ�����Ʒ����Ľӿڣ��ӿ������඼�ǳ����࣬����ʵ����������ʵ��
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

