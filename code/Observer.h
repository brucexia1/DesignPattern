#pragma once

#define NULL 0

#include <string>
#include <list>
using namespace std;

class CSubject;

class Observer
{
public:
    ~Observer();
    virtual void Update(CSubject*)=0;
protected:
    Observer();
};
class ConcreteObserverA : public Observer
{
public:
    ConcreteObserverA();
    ~ConcreteObserverA();
    virtual void Update(CSubject*);
private:
    string m_state;
};
class ConcreteObserverB : public Observer
{
public:
    ConcreteObserverB();
    ~ConcreteObserverB();
    virtual void Update(CSubject*);
private:
    string m_state;
};




class CSubject
{
public:
    ~CSubject();
    virtual void Notify();
    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual string GetState();
    virtual void SetState(string state);
protected:
    CSubject();
private:
    string m_state;
    list<Observer*> m_lst;
};
class ConcreteCSubjectA : public CSubject
{
public:
    ConcreteCSubjectA();
    ~ConcreteCSubjectA();
};
class ConcreteCSubjectB : public CSubject
{
public:
    ConcreteCSubjectB();
    ~ConcreteCSubjectB();
};
