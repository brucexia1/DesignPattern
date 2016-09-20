#pragma once

class Target 
{
public: 
	Target(); 
	virtual ~Target(); 
	virtual void Request() = 0; 
protected: 
private: 
}; 
class Adaptee 
{ 
public: 
	Adaptee(); 
	~Adaptee(); 
	void SpecificRequest(); 
protected: 
private: 
};

class Adapter : public Target
{
public:
	Adapter(Adaptee *ade);
	~Adapter(void);
	void Request();
private:
	Adaptee *_ade;
};

