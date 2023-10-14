/*
#include<stdio.h>
int main()
{
	char ch = 'a';
	int flag = 1;
	while (ch != '\n')
	{
		ch = getchar();
		if (ch >= 65 && ch <= 90)
		{
			ch = ch + 32;
		}
		if (ch == ' ')
		{
			flag = 1;
			printf(" ");
			continue;
		}
		if (flag == 1)
		{
			ch = ch - 32;
		}
		if(ch != ' ')
		{
			flag = 0;
		}
		printf("%c", ch);
	}
	return 0;
}
*/