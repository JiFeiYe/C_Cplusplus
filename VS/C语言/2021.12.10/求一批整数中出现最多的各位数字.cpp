//�ַ�������
/*todotodotodotodotodotodotodotodotodotodotodotodotodotodotodotodotodotodo
#include<stdio.h>

int a = 0;
//��ȡ���ֵ
int askmax(int *count)
{
	int max = 0;
	max = count[0];
	for (int i = 1; i < 10; i++)
	{
		if (max <= count[i])
		{
			max = count[i];
			
		}
	}
	return max;
}

int main()
{
	int N = 0;
	char a[1001] = { ' ' };
	int count[10] = { 0 };
	int max[1000] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf_s("%s", a, 1001);
		for (int j = 0; j < N; j++)//a�ӵ�0λ��ʼ����
		{
			for (int k = 48; k <= 57; k++)//k��ASCII���ж�Ӧ0~9
			{
				if (a[j] == k)
				{
					count[k-48]++;
				}
			}
		}
		//��count�������ֵ
		max[i] = askmax(count);
	}

}
*/