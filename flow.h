#pragma once
#include "control.h"
/******************************
ģ������Ŀ¼���й���
���в��������Ŀ��ĸ��ڵ����
���Զ����룬�ͷ�ʱ�Զ��Ӹ��ڵ��ͷ�
******************************/
class flow
{
	friend class flow;
private:
							//�ṹ��Ϣ
	flow* ph_nex;					//����ṹ���������ӣ���ֹ�ͷ�ʱ����
	flow* nex;						//һ�������ӣ�ָʾ��һ��������Ԫ
	flow* ext = 0;					//��չ���ӣ��������ṹ���ʵ��
								//ѭ������
	flow* loopsou;					//ѭ���ڵ�ָʾ

public:						//��Ҫ�����޸ĵĲ���
	int prefer = 1;					//ִ������ 0������	1��̰��
	int mintimes = 1;				//����ִ�д���
	int maxtimes = 1;				//���ִ�д�����0��ʾ����
								//ƥ��ģʽ,[]ר��
	bool not= false;				//���߼�

	control* order = 0;			//����߼�

public:						//�ṹ���ɷ���
	void addbranch(flow* newer);	//���ӷ�֧���·�֧�Ŀ�ͷΪnewer
	void endbranch(flow* newer);	//������֧�����з�֧�ս���newer   ע��_branch���������ڵ����
	void add(flow* newer);			//�����߼��������߼�newer
	void loop(flow* end, int min,
		int max = 0, int prefer = 1);//����ѭ��

private:					//ѭ���ṹ��Ӧ����
	void sucess();					//ѭ���ս��ſ��Ե���,����Ҳ��ʹ��
	void mefail();					//����λ�ö����Ե���,���ݸ���һ��ѭ���յ㣬���յ��׸�����getfail
	void getfail();

public:
	flow();
	~flow();
};

