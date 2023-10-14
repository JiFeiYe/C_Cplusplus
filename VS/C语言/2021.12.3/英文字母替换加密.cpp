/*
#include<stdio.h>
int main()
{
	char ch = 'a';
	while (ch != '\n')
	{
		ch = getchar();
		if (ch == 'y')
		{
			ch = 'Z';
			goto here;
		}
		else if (ch == 'Y')
		{
			ch = 'Z';
			goto here;
		}
		if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
		{
			if (ch >= 65 && ch < 89 || ch >= 97 && ch < 121)
			{
				ch = ch + 1;
			}
			if (ch >= 65 && ch < 89)
			{
				ch = ch + 32;
			}
			else if (ch >= 97 && ch < 121)
			{
				ch = ch - 32;
			}

			//Z z ÌØÊâ¿¼ÂÇ
			if (ch == 'z')
			{
				ch = 'A';
			}
			if (ch == 'Z')
			{
				ch = 'a';
			}
		}
		here:
		printf("%c", ch);
	}
	return 0;
}
*/