#pragma once


class Singleton
{
public:
	static Singleton *GetInstance();
	~Singleton(void);

protected:
	
private:
	Singleton(void);
	static Singleton *pInstance;
};

