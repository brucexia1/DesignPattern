#include "Interpret.hpp"

#include <iostream>
using namespace std;

AbstractExpression::AbstractExpression() 
{ 
} 
AbstractExpression::~AbstractExpression() 
{ 
} 


TerminalExpression::TerminalExpression(const string& statement) 
{
	_statement = statement; 
}
TerminalExpression::~TerminalExpression() 
{
} 
void TerminalExpression::Interpret(const ContextIpt& c) 
{ 
	cout<<_statement<<" TerminalExpression"<<endl;
}


NonterminalExpression::NonterminalExpression(AbstractExpression* expression,int times) 
{ 
	_expression = expression; 
	_times = times; 
} 
NonterminalExpression::~NonterminalExpression() 
{ 
} 
void NonterminalExpression::Interpret(const ContextIpt& c) 
{
	for (int i = 0; i < _times ; i++) 
	{ 
		_expression->Interpret(c);
	} 
} 








ContextIpt::ContextIpt() 
{
}
ContextIpt::~ContextIpt() 
{
}
void ContextIpt::GlobalInfo()
{
	cout<< "global description info" <<endl;
}
