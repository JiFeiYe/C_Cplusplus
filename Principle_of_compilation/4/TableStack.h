#ifndef _TABLESTACK_H_
#define _TABLESTACK_H_
#include "Base.h"
class TableStack : public Base
{
	char table[50][50]; // 存放优先表
	int step;			// 序号
	char S[100];		// 符号栈
public:
	TableStack() : step(1)
	{
		memset(table, 0, sizeof(table)); // 置空字符串
		memset(S, 0, sizeof(S));
	}
	void out();
};
#endif
