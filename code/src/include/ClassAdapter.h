#pragma once

class ClassTarget
{
public:
	ClassTarget();
	virtual ~ClassTarget();
	virtual void Request() = 0;
};

class ClassAdaptee 
{
public:
	ClassAdaptee();
	~ClassAdaptee();
	void SpecificRequest();
};

//通过private继承ClassAdaptee获得实现继承的效果，
//而通过public继承ClassTarget获得接口继承的效果。
//在 C++中的 public继承既是接口继承又是实现继承，因为子类在继承了父类后既可以
//对外提供父类中的接口操作，又可以获得父类的接口实现。
class ClassAdapter : public ClassTarget, private ClassAdaptee
{
public:
	ClassAdapter(void);
	~ClassAdapter(void);
	void Request();
};

