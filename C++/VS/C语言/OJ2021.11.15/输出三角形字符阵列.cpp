/*
#include<stdio.h>
int main()
{
	int n = 0, ascii = 65, l = 0;					//n行，ascii用于ASCII码，l用于每行个数限制
	scanf_s("%d", &n);
	l = n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = l; k >= 1; k--)
		{
			printf("%c ", ascii);
			ascii++;
		}
		l--;
		printf("\n");
	}
	return 0;
}
*/