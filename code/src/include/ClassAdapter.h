#pragma once

class ClassTarget
{
public:
	ClassTarget();
	virtual ~ClassTarget();
	virtual void Request() = 0;
};

class ClassAdaptee 
{
public:
	ClassAdaptee();
	~ClassAdaptee();
	void SpecificRequest();
};

//ͨ��private�̳�ClassAdaptee���ʵ�ּ̳е�Ч����
//��ͨ��public�̳�ClassTarget��ýӿڼ̳е�Ч����
//�� C++�е� public�̳м��ǽӿڼ̳�����ʵ�ּ̳У���Ϊ�����ڼ̳��˸����ȿ���
//�����ṩ�����еĽӿڲ������ֿ��Ի�ø���Ľӿ�ʵ�֡�
class ClassAdapter : public ClassTarget, private ClassAdaptee
{
public:
	ClassAdapter(void);
	~ClassAdapter(void);
	void Request();
};

