#pragma once

class Aggregate;
typedef int Object;
class Iterator
{
public:
	virtual ~Iterator(void);
	virtual void First() = 0; 
	virtual void Next() = 0; 
	virtual bool IsDone()    = 0; 
	virtual Object CurrentItem() = 0;
protected:
	Iterator(void);
};

class ConcreteIterator:public Iterator 
{ 
public: 
	ConcreteIterator(Aggregate* ag , int idx = 0); 
	~ConcreteIterator(); 
	void First(); 
	void Next(); 
	bool IsDone(); 
	Object CurrentItem(); 
protected: 
private: 
	Aggregate* _ag;
	int _idx;
};





class Iterator; 
//typedef int Object;
class Aggregate 
{
public: 
	virtual ~Aggregate();
	virtual Iterator* CreateIterator() = 0;
	virtual Object GetItem(int idx) = 0;
	virtual int GetSize() = 0;
protected:
	Aggregate();
};
class ConcreteAggregate:public Aggregate 
{
public: 
	enum {SIZE = 3}; 
	ConcreteAggregate(); 
	~ConcreteAggregate(); 
	Iterator* CreateIterator(); 
	Object GetItem(int idx); 
	int GetSize(); 
protected: 
private: 
	Object _objs[SIZE]; 
};