#pragma once

/************************************************
ģ��˵����
�洢��С�жϽڵ�
*************************************************/
class flow;
class control
{
private :
	friend class flow;
	int point;
public:							//��Ҫ�����޸ĵĲ���
	int type;
	int state;
public:
	control();
	~control();

	bool test(char* target);	//���ִ����в���
};

