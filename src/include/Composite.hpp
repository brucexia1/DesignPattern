#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
#define NULL 0


class Compt
{
public:
	Compt(void);
	virtual ~Compt(void);
	virtual void Operation() = 0;
	virtual void Add(Compt *) {return;};
	virtual void Remove(Compt *) {return;};
	virtual Compt * GetChild(int) {return NULL;};
};

class Leaf:public Compt 
{
public: 
	Leaf();
	~Leaf();
	void Operation();
}; 

class Composite : public Compt
{
public:
	Composite(void);
	~Composite(void);
	
	void Operation();
	void Add(Compt * com);
	void Remove(Compt * com);
	Compt * GetChild(int index);

private:
	vector<Compt*> comVec;
};

