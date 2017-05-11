#pragma once
#include <string>

using namespace std;

//����洢Originator������ڲ�״̬�����ɷ�ֹOriginator���������������ʱ���¼Memento��
//����¼�������ӿڣ�Caretakerֻ�ܿ�������¼��խ�ӿڣ���ֻ�ܽ�����¼���ݸ���������Originator�ܹ�����һ����ӿڣ����������ʷ��ص���ǰ״̬������������ݡ�
class Memento
{
private:
    //��OriginatorΪfriend�࣬���Է����ڲ���Ϣ�����������಻�ܷ���
    friend class Originator;
    Memento(const string& state);
    ~Memento();
    void SetState(const string& state);
    string GetState();
    string _state;
};

//���𴴽�һ������¼Memento�����Լ�¼��ǰʱ�������ڲ�״̬������ʹ�ñ���¼�ָ��ڲ�״̬
class Originator
{
public:
    Originator();
    Originator(const string& state);
    ~Originator();
    void RestoreToMemento(Memento* pMemento);
    Memento* CreateMemento();
    void SetState(const string& state);
    string GetState();
    void show();
protected:
private:
    string _state;
};

//���𱣴�ñ���¼Memento,���ܶԱ���¼�����ݽ��в�������
class Caretaker
{
public:
    Caretaker();
    ~Caretaker();
    void SetMemento(Memento*);
    Memento* GetMemento();
private:
    Memento* _memento;
};
