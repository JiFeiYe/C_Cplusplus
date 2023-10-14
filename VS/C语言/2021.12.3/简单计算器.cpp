/*
#include<stdio.h>
int main()
{
	char ch = 'a';
	int a,b;
	scanf_s("%d", &a);
	int result = 0;
	while((ch = getchar()) != '=')
	{
		scanf_s("%d", &b);
		if (ch == '/' && b == 0)
		{
			printf("ERROR");
			return 0;
		}

				if (ch == '+')
				{
					result = a + b;
				}
				else if (ch == '-')
				{
					result = a - b;
				}
				else if (ch == '*')
				{
					result = a * b;
				}
				else if (ch == '/')
				{
					result = a / b;
				}
				else
				{
					printf("ERROR");
					return 0;
				}

		a = result;
	}
	printf("%d", a);
	return 0;
}
*/