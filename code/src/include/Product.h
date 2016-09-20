#pragma once
class AbstractProductPen
{
public:
	virtual ~AbstractProductPen(void) = 0;
protected:
	AbstractProductPen(void);
private:
};

class AbstractProductBook
{
public:
	virtual ~AbstractProductBook(void) = 0;
protected:
	AbstractProductBook(void);
private:
};


class ProductPenRed:public AbstractProductPen
{ 
public: 
	~ProductPenRed();
	ProductPenRed();
protected:
private:
};
class ProductPenGreen:public AbstractProductPen
{
public:
	~ProductPenGreen();
	ProductPenGreen();
protected: 
private:
};

class ProductBookRed:public AbstractProductBook
{
public: 
	~ProductBookRed();
	ProductBookRed();
protected: 
private: 
};
class ProductBookGreen:public AbstractProductBook
{ 
public: 
	~ProductBookGreen();
	ProductBookGreen();
protected: 
private: 
};
