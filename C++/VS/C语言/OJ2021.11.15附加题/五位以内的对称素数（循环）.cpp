/*
#include<stdio.h>
#include<stdio.h>

//判断回文数
int text1(int n)
{
	int j = 0, k = 0;
	j = n;
	while (j)
	{
		k = k * 10 + j % 10;		//将整数倒序输出
		j /= 10;
	}
	if (k == n)
	{
		return 1;					//是回文数
	}
	return 0;						//不是回文数
}

//判断素数
int text2(int n)
{
	if (n == 2)
	{
		return 1;							//是素数
	}
	else if (n == 1)
	{
		return 0;							//不是素数
	}
	else
	{
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)					//不是素数
			{
				return 0;
			}
		}
	}
	return 1;								//是素数
}

int main()
{
	int T = 0, n = 0, text1_ = 1, text2_ = 1;					//T组测试样例，n为被测数
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf_s("%d", &n);
		text1_ = text1(n);
		text2_ = text2(n);
		if (text1_ == 1 && text2_ == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
*/