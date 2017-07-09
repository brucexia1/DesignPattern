#include "Character.hpp"

#include <iostream>
using namespace std; 

Character::Character(void)
{
}
Character::~Character(void)
{
}


CharacterA::CharacterA()  
{  
    this->m_chSymbol = 'A';  
    this->m_nWeight = 100;  
    this->m_nHeight = 200;  
}
CharacterA::~CharacterA()  
{ 
}
void CharacterA::SetSize(int nWeight, int nHeight)  
{  
    this->m_nWeight = nWeight;  
    this->m_nHeight = nHeight;  
}  
void CharacterA::Display()  
{  
    cout << "CharacterA：" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;  
}

CharacterB::CharacterB()  
{
    this->m_chSymbol = 'B';  
    this->m_nWeight = 100;  
    this->m_nHeight = 200;  
}
CharacterB::~CharacterB()  
{
}  
void CharacterB::SetSize(int nWeight, int nHeight)  
{
    this->m_nWeight = nWeight;  
    this->m_nHeight = nHeight;  
}
void CharacterB::Display()  
{
    cout << "CharacterB：" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;  
}




CharacterFactory::CharacterFactory()  
{
    m_mChar.insert(make_pair<char, Character*>('A', new CharacterA));  
    m_mChar.insert(make_pair<char, Character*>('B', new CharacterB));  
}
CharacterFactory::~CharacterFactory()  
{
}
Character* CharacterFactory::GetCharacter(char chIn)
{  
    map<char, Character*>::iterator it = m_mChar.find(chIn);
    if(it != m_mChar.end())
    {
        return (Character*)it->second;
    }
    return NULL;
}
