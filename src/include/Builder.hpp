#pragma once

#include <string>
#include <vector>
using namespace std;


//��Ʒ��
class BldProduct
{
private:
    string m_partA;
    string m_partB;
    string m_partC;
public:
    void setPartA(const string& s);
    void setPartB(const string& s);
    void setPartC(const string& s);
    BldProduct();
    ~BldProduct();
};




//����Builder���࣬���岻ͬ���ֵĴ����ӿ�
class Builder
{
public:
    virtual void BuildPartA()=0;
    virtual void BuildPartB()=0;
    virtual void BuildPartC()=0;
    virtual BldProduct* GetProduct()=0;
    Builder();
    virtual ~Builder();
};




//  Builder��������,ʵ��BuilderPartA��BuilderPartB��BuildPartC�ӿں��� 
class ConcreteBuilder1:public Builder
{
public:
    ConcreteBuilder1();
    ~ConcreteBuilder1();
    virtual void BuildPartA();
    virtual void BuildPartB();
    virtual void BuildPartC();
    virtual BldProduct* GetProduct();
private:
    BldProduct* m_pProduct;
};

//  Builder��������,ʵ��BuilderPartA��BuilderPartB��BuildPartC�ӿں��� 
class ConcreteBuilder2:public Builder
{
public:
    ConcreteBuilder2();
    ~ConcreteBuilder2();
    virtual void BuildPartA();
    virtual void BuildPartB();
    virtual void BuildPartC();
    virtual BldProduct* GetProduct();
private:
    BldProduct* m_pProduct;
};





 // ʹ��Builder������Ʒ,������Ʒ�Ĺ��̶�һ��,���ǲ�ͬ��builder�в�ͬ��ʵ��
 // �����ͬ��ʵ��ͨ����ͬ��Builder��������ʵ��,����һ��Builder��ָ��,ͨ�������ʵ�ֶ�̬���� 
class Director
{
public:
    Director(Builder* pBuilder);
    ~Director();

    //Construct��������һ�������������������,��ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
    //���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ 
    void Construct();
    //void Construct(const string& buildPara);
private:
    Builder* m_pBuilder;
};

