/*
#include<stdio.h>

//�ж�����
int prime(int n)
{
	int i = 0;
	if (n == 1)
	{
		return 0;							//��������
	}
	if (n == 2)
	{
		return 0;							//������,���ǲ��ܰ�����ȥ
	}
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;						//��������
		}
	}
	return 1;								//������
}

int main() {
	int m = 0, n = 0, count = 0;
	scanf_s("%d%d", &m, &n);
	for (int i = m; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if ((prime(j) == 1) && (prime(i-j) == 1)) {
				count++;
				if (count % 5 == 0 && count != 0) {
					printf("%d=%d+%d\n", i, j, i - j);
				}
				else {
					printf("%d=%d+%d, ", i, j, i - j);
				}
				break;
			}
		}
	}
	return 0;
}
*/