/*
#include<stdio.h>

//判断素数
int prime(int n)
{
	int i = 0;
	if (n == 1)
	{
		return 0;							//不是素数
	}
	if (n == 2)
	{
		return 0;							//是素数,但是不能包括进去
	}
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;						//不是素数
		}
	}
	return 1;								//是素数
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