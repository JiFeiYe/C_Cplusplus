/*
#include<stdio.h>

//�Զ�����
int cycle(int a)					//n->a
{
	int i = 0;
	for(i = 0; a != 1; i++)
	{
		if (a % 2 == 0)				//ż��
		{
			a /= 2;
		}
		else						//����
		{
			a = 3 * a + 1;
		}
	}
	return i;
}

int main()
{
	int team = 0, n = 0, count = 0;				//count��������
	scanf_s("%d", &team);
	while (team != 0)
	{
		scanf_s("%d", &n);
		count = cycle(n);
		team--;
		printf("%d ", count);
	}
	return 0;
}
*/