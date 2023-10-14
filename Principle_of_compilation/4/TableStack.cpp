#include "TableStack.h"
#include <string>

void TableStack::out()
{
	char str3[100] = {0}; // 用于存放一个产生式子
	char str2[100];		  // 用于存放待检测的字符串
	char filename[10];	  // 文件名
	int length = 0;		  // 记录产生式个数
	cout << "请输入文件名：";
	cin >> filename;
	ifstream fin(filename);
	if (!fin)
	{
		cout << "Cannot open the file.\n"; // 未找到对应的文件名的文件
		exit(1);
	}
	while (fin)
	{
		fin.getline(str3, 100); // 读出一个产生式
		cout << str3 << endl;
		pro[length].Left = str3[0]; // 产生式的左部
		strcpy(pro[length].Right, str3 + 3);
		length++;
	}
	length -= 1;
	is_gram(pro, length);
	cout << "各非终结符的FIRSTOP集合如下：" << endl;
	FIRSTOP(pro, firstop, length);
}
