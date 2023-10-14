/*
#include<stdio.h>
int main()
{
	char str[80] = { ' ' };
	char str1[80] = { ' ' };
	int i = 0;
	while ((str[i] = getchar()) != '#')
	{
		i++;
	}
	str[i] = '\0';
	int m = 0, temp = 0;
	for (int j = 0; j < i; j++)
	{
		if (str[j] >= '0' && str[j] <= '9' || str[j] >= 'a' && str[j] <= 'f' || str[j] >= 'A' && str[j] <= 'F')
		{
			temp = j;
			break;
		}
	}
	for (int k = 0; k < temp; k++)//ÅĞ¶Ï¸ºÊı
	{
		if (str[k] == '-')
		{
			str1[m] = '-';
			m = 1;
			break;
		}
	}
	for (int j = 0; j < i; j++)
	{
		if (str[j] >= '0' && str[j] <= '9' || str[j] >= 'a' && str[j] <= 'f' || str[j] >= 'A' && str[j] <= 'F')
		{
			str1[m] = str[j];
			m++;
		}
	}
	long int num = 0;
	for (int j = 1; j < i; j++)
	{
		if(str[j] >= '0' && str[j] <= '9')
		{
			num = num * 16 + (str[j] - 48);
		}
		else if (str[j] >= 'A' && str[j] <= 'F')
		{
			num = num * 16 + (str[j] - 55);
		}
		else if (str[j] >= 'a' && str[j] <= 'f')
		{
			num = num * 16 + (str[j] - 87);
		}
	}
	if (str1[0] == '-')
	{
		num = -num;
	}
	printf("%ld", num);
	return 0;
}
*/