#pragma once

/************\
将请求的接收者（处理者）放到 Command 的具体子类ConcreteCommand 中，
当请求到来时（Invoker 发出 Invoke 消息激活 Command 对象） ，
ConcreteCommand 将处理请求交给 Receiver对象进行处理。
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
