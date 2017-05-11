#pragma once

#include <string>
using namespace std;

class ContextIpt;
class AbstractExpression 
{ 
public: 
	virtual ~AbstractExpression(); 
	virtual void Interpret(const ContextIpt& c) = 0;
protected: 
	AbstractExpression(); 
}; 
class TerminalExpression:public AbstractExpression 
{ 
public: 
	TerminalExpression(const string& statement); 
	~TerminalExpression(); 
	void Interpret(const ContextIpt& c); 
protected: 
private: 
	string _statement; 
}; 
class NonterminalExpression:public AbstractExpression 
{ 
public: 
	NonterminalExpression(AbstractExpression* expression,int times); 
	~ NonterminalExpression(); 
	void Interpret(const ContextIpt& c); 
protected: 
private: 
	AbstractExpression* _expression; 
	int _times; 
}; 






class ContextIpt 
{ 
public: 
	ContextIpt();
	~ContextIpt();
	void GlobalInfo();
};