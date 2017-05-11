#pragma once

/************\
������Ľ����ߣ������ߣ��ŵ� Command �ľ�������ConcreteCommand �У�
��������ʱ��Invoker ���� Invoke ��Ϣ���� Command ���� ��
ConcreteCommand ���������󽻸� Receiver������д���
\************/

class Command
{
public:
    virtual ~Command();
    virtual void Execute()=0;
protected:
    Command();
private:
};

class Receiver;

class ConcreteCommandA : public Command
{
public:
    ConcreteCommandA(Receiver* pReceiver);
    ~ConcreteCommandA();
    virtual void Execute();
protected:
private:
    Receiver* m_recv;
};

//template<class Receiver>
class ConcreteCommandB : public Command
{
public:
    ConcreteCommandB(Receiver* pReceiver);
    ~ConcreteCommandB();
    virtual void Execute();

	typedef void (Receiver:: *ActionFun)();
	ConcreteCommandB(Receiver* pReceiver, ActionFun actFun);
protected:
private:
    Receiver* m_recv;
	ActionFun m_actFun;
};


class Receiver
{
public:
    Receiver();
    ~Receiver();
    void Action();
};


class Invoker
{
public:
    Invoker(Command* pCommand);
    ~Invoker();
    void Invoke();
protected:
private:
    Command* m_cmd;
};
