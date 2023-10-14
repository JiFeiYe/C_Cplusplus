/*
#include<stdio.h>
int main()
{
	int N = 0;
	scanf_s("%d", &N);
	int temp = 1, flag = 0;
	int a[10][10] = { 0 };
	for (int k = 0; k < N / 2 + 1; k++)
	{
		int j = 0;
		for (j = k; j <= N - 1 - k; j++)
		{
			a[k][j] = temp;
			temp++;
		}
		int i = 0;
		for (j = k + 1; j < N - k; j++) 
		{
			a[j][N - k - 1] = temp++;
		}
		int l = 0;
		for ( l = N - k - 2; l >= k; l--) 
		{
			a[N - k - 1][l] = temp++;
		}
		int p = 0;
		for (p = N - k - 2; p >= k + 1; p--)
		{
			a[p][k] = temp++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/