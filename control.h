#pragma once

/************************************************
模块说明：
存储最小判断节点
*************************************************/
class flow;
class control
{
private :
	friend class flow;
	int point;
public:							//需要解析修改的部分
	int type;
	int state;
public:
	control();
	~control();

	bool test(char* target);	//对字串进行测试
};

