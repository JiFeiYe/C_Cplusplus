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
	str[i] = '\0';
	int i1 = 0;
	for (int j = 0; j < i; j++)
	{
		if (str[j] >= 'A' && str[j] <= 'Z')
		{
			str1[i1] = str[j];
			i1++;
		}
	}

	int flag = 1;
	if (i1 == 0)
	{
		printf("Not Found");
	}
	else
	{
		for (int j = 0; j < i1; j++)
		{
			for (int k = 0; k < j; k++)
			{
				flag = 1;
				if (str1[j] == str1[k])
				{
					flag = 0;
					break;
				}
				
			}
			if (flag == 1)
			{
				printf("%c", str1[j]);
			}
		}
	}

	return 0;
}
*/