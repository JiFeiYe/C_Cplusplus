/*
#include<stdio.h>
int main()
{
	char str[80] = { ' ' };
	int offset = 0;
	int i = 0;
	while ((str[i] = getchar()) != '\n')
	{
		i++;
	}
	str[i] = '\0';
	scanf("%d", &offset);
	offset = offset % 26;

	for (int j = 0; j < i; j++)
	{
		if (str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z')
		{
			str[j] = str[j] + offset;
			if ((str[j] <= 'A' || str[j] >= 'Z' && str[j] <= 'a' || str[j] >= 'z') && offset >= 0)
				str[j] = str[j] - 26;
			else if ((str[j] <= 'A' || str[j] >= 'Z' && str[j] <= 'a' || str[j] >= 'z') && offset <= 0)
				str[j] = str[j] + 26;
		}

	}

	for (int j = 0; j < i; j++)
	{
		printf("%c", str[j]);
	}
	return 0;
}
*/