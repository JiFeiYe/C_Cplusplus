/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char chess[3][3] = { ' ' };
int count1[3][3] = { 1 };
int main()
{
	int i = 0, j = 0;
	srand((unsigned)time(0));
	int temp = 100;
	while (temp != 0)
	{
		i = (rand() % 15)/5;
		j = (rand() % 15)/5;
		printf("%d %d\n", i, j);
		temp--;
	}
	return 0;
}
*/