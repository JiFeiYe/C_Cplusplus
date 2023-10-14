//字符串方法
/*todotodotodotodotodotodotodotodotodotodotodotodotodotodotodotodotodotodo
#include<stdio.h>

int a = 0;
//获取最大值
int askmax(int *count)
{
	int max = 0;
	max = count[0];
	for (int i = 1; i < 10; i++)
	{
		if (max <= count[i])
		{
			max = count[i];
			
		}
	}
	return max;
}

int main()
{
	int N = 0;
	char a[1001] = { ' ' };
	int count[10] = { 0 };
	int max[1000] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf_s("%s", a, 1001);
		for (int j = 0; j < N; j++)//a从第0位开始遍历
		{
			for (int k = 48; k <= 57; k++)//k是ASCII码中对应0~9
			{
				if (a[j] == k)
				{
					count[k-48]++;
				}
			}
		}
		//求count数组最大值
		max[i] = askmax(count);
	}

}
*/