#pragma once


class Subsystem1
{
public:
	Subsystem1();
	~Subsystem1();
	void Operation();
};

class Subsystem2
{
public:
	Subsystem2();
	~Subsystem2();
	void Operation();
};

class Facade
{
public:
	Facade(void);
	~Facade(void);
	void OperationWrapper();
private:
	Subsystem1 *m_subs1;
	Subsystem2 *m_subs2;
};

