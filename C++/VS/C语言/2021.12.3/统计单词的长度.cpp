/*
#include<stdio.h>
int main()
{
	char ch = 'a';
	int flag = 1, count1 = 0, count2 = 0, count3 = 0;
	int a[500] = { 0 };
	while (1)
	{
		ch = getchar();

		//��������ѭ��
		if (ch == '\n' && flag == 0)
		{
			a[count2] = count1;
			break;
		}
		else if (ch == '\n' && flag == 1)
		{
			if (count2 == 0)//ȫ�ǿո�
			{
				break;
			}
			else
			{
				count2--;
				break;
			}
		}

		//���ڼ���
		if (ch != ' ')
		{
			count1++;
			flag = 0;
		}
		else if (ch == ' ' && flag == 0)
		{
			a[count2] = count1;
			count2++;
			count1 = 0;
			flag = 1;
		}
	}
	for (int i = 0; i <= count2; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
*/