/*
#include<stdio.h>
int main()
{
	char str[80] = { ' ' }, str1[80] = { ' ' };
	int i = 0;
	while ((str[i] = getchar()) != '\n')
	{
		i++;
	}
	str[i] = ' ';
	//ÌŞ³ıÖØ¸´
	int flag = 1, m = 0;
	for (int j = 0; j < i; j++)
	{
		flag = 1;
		for (int k = 0; k < j; k++)
		{
			if (str[j] == str1[k])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			str1[m] = str[j];
			m++;
		}
	}
	//ÅÅĞò
	int temp = 0;
	for (int k = 0; k < i; k++)
	{
		for (int j = k; j < i; j++)
		{
			if (str1[k] > str1[j])
			{
				temp = str1[k];
				str1[k] = str1[j];
				str1[j] = temp;
			}
		}
	}
	for (int j = 0; j < i; j++)
	{
		printf("%c", str1[j]);
	}
	return 0;
}
*/