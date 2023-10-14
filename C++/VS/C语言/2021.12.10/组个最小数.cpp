#include<stdio.h>
int main()
{
	int a1[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &a1[i]);
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += a1[i];
	}


	int a2[50] = { 0 };
	int index = 0;
	if (a1[0] == 0)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < a1[i]; j++)
			{
				a2[index] = i;
				index++;
			}
		}
	}
	else if (a1[0] != 0)
	{
		int temp = 0;
		for (temp = 1; temp < 10; temp++)
		{
			if (a1[temp] != 0)
				break;
		}
		a2[index] = temp;
		a1[temp]--;
		index++;
		for (int i = 0; i < a1[0]; i++)
		{
			a2[index] = 0;
			index++;
		}
		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < a1[i]; j++)
			{
				a2[index] = i;
				index++;
			}
		}
	}
	for (int i = 0; i < sum; i++)
	{
		printf("%d", a2[i]);
	}
	return 0;
}