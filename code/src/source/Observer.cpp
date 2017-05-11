#include "Observer.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

Observer::Observer()
{}
Observer::~Observer()
{}


ConcreteObserverA::ConcreteObserverA()
{}
ConcreteObserverA::~ConcreteObserverA()
{}
void ConcreteObserverA::Update(CSubject* pCSubject)
{
    m_state = pCSubject->GetState();
    cout << "The ConcreteObserverA is " << m_state << std::endl;
}


ConcreteObserverB::ConcreteObserverB()
{}
ConcreteObserverB::~ConcreteObserverB()
{}
void ConcreteObserverB::Update(CSubject* pCSubject)
{
    m_state = pCSubject->GetState();
    cout << "The ConcreteObserverB is " << m_state << std::endl;
}





CSubject::CSubject()
{}
CSubject::~CSubject()
{}
void CSubject::Attach(Observer* pObserver)
{
	if(NULL != pObserver){
		m_lst.push_back(pObserver);
	}
}
void CSubject::Detach(Observer* pObserver)
{
	if(NULL == pObserver)  return;
    list<Observer*>::iterator iter;
    iter = find(m_lst.begin(),m_lst.end(),pObserver);
    if(iter != m_lst.end())
    {
        m_lst.erase(iter);
    }
}
void CSubject::Notify()
{
    list<Observer*>::iterator iter = m_lst.begin();
    for(;iter != m_lst.end();iter++)
    {
        (*iter)->Update(this);
    }
}
string CSubject::GetState()
{
    return m_state;
}
void CSubject::SetState(string state)
{
    m_state = state;
}


ConcreteCSubjectA::ConcreteCSubjectA()
{}
ConcreteCSubjectA::~ConcreteCSubjectA()
{}


ConcreteCSubjectB::ConcreteCSubjectB()
{}
ConcreteCSubjectB::~ConcreteCSubjectB()
{}
