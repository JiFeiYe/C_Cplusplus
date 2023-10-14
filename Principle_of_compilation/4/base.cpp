#include "base.h"
int Base::is_VN(char ch) // 判断是否是非终结符，默认大写字母为非终结符，其他为终结符
{
	if (ch >= 'A' && ch <= 'Z')
		return 1;
	else
		return 0;
}
void Base::is_gram(Proce pro[], int length) // 判断文法是否为算符文法
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < strlen(pro[i].Right) - 1; j++)
			if (is_VN(pro[i].Right[j]) == 1 && is_VN(pro[i].Right[j + 1]) == 1) // 两个非终结符在一起了
			{
				flag = 1;
				break;
			}
	}
	if (flag == 1)
	{
		cout << "该文法不是算符文法！" << endl;
		return;
	}
	else
		cout << "该文法是算符文法！" << endl;
}
void Base::NoAdd(Myset VNT[], int length1) // 去掉集合中重复部分
{
	char str1[20];		// 非终结符
	char str2[20][100]; // 终结符
	int length;
	for (int i = 0; i < length1; i++)
	{
		str1[i] = VNT[i].VN;
		strcpy(str2[i], VNT[i].VT); // 把终结符复制给str2
	}
	for (int i = 0; i < length1; i++)
		memset(VNT[i].VT, 0, sizeof(VNT[i].VT)); // 清空
	for (int i = 0; i < length1; i++)
	{
		int t = 0;
		for (int j = 0; j < strlen(str2[i]); j++)
		{
			flag = 1;
			for (int k = 0; k < t; k++)
				if (VNT[i].VT[k] == str2[i][j]) // 重复了
					flag = 0;
			if (flag == 1)
				VNT[i].VT[t++] = str2[i][j];
		}
		length = strlen(VNT[i].VT);
	}
}
// 求各非终结符的FIRSTOP集合
void Base::FIRSTOP(Proce pro[], Myset firstop[], int length)
{
	int m = 0; // 非终结符个数，flag记录产生式个数
	int j, k;
	while (flag < length) // length产生式总个数
	{
		j = 0;
		firstop[m].VN = pro[flag].Left;
		while (firstop[m].VN == pro[flag].Left)
		{
			if (is_VN(pro[flag].Right[0]) == 0) // P->a...则将a加入firstvt(P)中
				firstop[m].VT[j++] = pro[flag].Right[0];
			else if (is_VN(pro[flag].Right[0]) == 1 && is_VN(pro[flag].Right[1]) == 0) // P->Qa...则将a加入firstvt(P)中
				firstop[m].VT[j++] = pro[flag].Right[1];
			flag++;
		}
		m++;
	}
	for (int i = length - 1; i >= 0; i--) // P->Q...，则将Q中的终结符加入P中
		if (is_VN(pro[i].Right[0]) == 1 && pro[i].Left != pro[i].Right[0])
		{
			for (j = 0; j < m; j++) // E->E跳出
				if (firstop[j].VN == pro[i].Right[0])
					break;
			for (k = 0; k < m; k++)
				if (firstop[k].VN == pro[i].Left)
					break;
			strcat(firstop[k].VT, firstop[j].VT); // firstop[j].VT添加到firstvt[k].VT后面（strcat字符串连接函数)
		}
	NoAdd(firstop, m);			// 去重
	for (int i = 1; i < m; i++) // 集合输出
	{
		cout << "FIRSTOP(";
		cout << firstop[i].VN << ")" << "=" << "{";
		cout << firstop[i].VT[0];
		for (int j = 1; j < strlen(firstop[i].VT); j++)
			cout << "," << firstop[i].VT[j];
		cout << "}" << endl;
	}
}
