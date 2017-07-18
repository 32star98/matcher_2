#pragma once
#include "control.h"
/******************************
模仿树形目录进行构造
所有操作均针对目标的根节点进行
不自动申请，释放时自动从根节点释放
******************************/
class flow
{
	friend class flow;
private:
							//结构信息
	flow* ph_nex;					//申请结构，线性连接，防止释放时出错
	flow* nex;						//一般性连接，指示下一个操作单元
	flow* ext = 0;					//扩展连接，用于树结构广度实现
								//循环控制
	flow* loopsou;					//循环节点指示

public:						//需要解析修改的部分
	int prefer = 1;					//执行倾向 0，懒惰	1，贪婪
	int mintimes = 1;				//最少执行次数
	int maxtimes = 1;				//最大执行次数，0表示无限
								//匹配模式,[]专用
	bool not= false;				//非逻辑

	control* order = 0;			//外接逻辑

public:						//结构生成方法
	void addbranch(flow* newer);	//增加分支，新分支的开头为newer
	void endbranch(flow* newer);	//结束分支，所有分支终结于newer   注：_branch方法由树节点调用
	void add(flow* newer);			//增长逻辑，附加逻辑newer
	void loop(flow* end, int min,
		int max = 0, int prefer = 1);//设置循环

private:					//循环结构响应函数
	void sucess();					//循环终结点才可以调用,自身也会使用
	void mefail();					//所有位置都可以调用,传递给下一个循环终点，由终点抛给起点的getfail
	void getfail();

public:
	flow();
	~flow();
};

