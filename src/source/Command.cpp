#include "Command.hpp"

#include <iostream>
using namespace std;

Command::Command()
{}
Command::~Command()
{}



ConcreteCommandA::ConcreteCommandA(Receiver* pReceiver)
{
    m_recv = pReceiver;
}
ConcreteCommandA::~ConcreteCommandA()
{}
void ConcreteCommandA::Execute()
{
    m_recv->Action();
}



ConcreteCommandB::ConcreteCommandB(Receiver* pReceiver)
{
    m_recv = pReceiver;
}

ConcreteCommandB::ConcreteCommandB(Receiver* pReceiver, ActionFun actFun)
{
	m_recv = pReceiver;
	m_actFun = actFun;
}

ConcreteCommandB::~ConcreteCommandB()
{
}

void ConcreteCommandB::Execute()
{
    //this->_recv->Action();
	(m_recv->*m_actFun)();
}



Receiver::Receiver()
{}
Receiver::~Receiver()
{}
void Receiver::Action()
{
    cout << "Receiver::Action" << endl;
}



Invoker::Invoker(Command* pCommand)
{
    m_cmd = pCommand;
}
Invoker::~Invoker()
{}
void Invoker::Invoke()
{
    m_cmd->Execute();
}
