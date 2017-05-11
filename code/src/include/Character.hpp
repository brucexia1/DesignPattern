#pragma once

#include <map>  

class Character
{
public:
	virtual ~Character(void);
	virtual void SetSize(int, int) = 0;  
    virtual void Display() = 0; 
protected:
	Character(void);
	char m_chSymbol;  
    int m_nWeight;  
    int m_nHeight;
};


class CharacterA : public Character  
{  
public:  
    CharacterA();
    virtual ~CharacterA();
    void SetSize(int, int);
    void Display();
};

class CharacterB : public Character  
{  
public:  
    CharacterB();  
    virtual ~CharacterB();
    void SetSize(int, int);  
    void Display();  
};



class CharacterFactory    
{  
public:  
    CharacterFactory();  
    virtual ~CharacterFactory();  
  
    Character* GetCharacter(char);  
private:  
    std::map<char, Character*> m_mChar;  
};