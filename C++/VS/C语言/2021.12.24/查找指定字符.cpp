/*
#include<stdio.h>
int main()
{
	char s = ' ', str[80] = { ' ' };
	s = getchar();
	getchar();
	int i = 0;
	while ((str[i] = getchar()) != '\n')
	{
		i++;
	}
	str[i] = '\0';
	int num = -1;
	for (int j = 0; j < i; j++)
	{
		if (str[j] == s)
		{
			num = j;
		}
	}
	if (num == -1)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("index = %d", num);
	}
	return 0;
}
*/