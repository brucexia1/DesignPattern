#include "Memento.hpp"

#include <iostream>
#include <string>

using namespace std;

Memento::Memento(const string& state)
{
    _state = state;
}
Memento::~Memento()
{}
string Memento::GetState()
{
    return _state;
}
void Memento::SetState(const string& state)
{
    _state = state;
}



Originator::Originator()
{}
Originator::Originator(const string& state)
{
    _state = state;
}
Originator::~Originator()
{}
string Originator::GetState()
{
    return _state;
}
void Originator::show()
{
    cout << _state << endl;
}
void Originator::SetState(const string& state)
{
    _state = state;
}
Memento* Originator::CreateMemento()
{
    return new Memento(_state);
}
void Originator::RestoreToMemento(Memento* pMemento)
{
    _state = pMemento->GetState();
}



Caretaker::Caretaker()
{}
Caretaker::~Caretaker()
{}
Memento* Caretaker::GetMemento()
{
    return _memento;
}
void Caretaker::SetMemento(Memento* pMemento)
{
    _memento = pMemento;
}
