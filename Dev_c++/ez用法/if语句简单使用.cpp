#include<stdio.h>
int main()
{
	int i;
	printf("Please enter a number:\n");			
	scanf("%d",&i);
	if(i>=10) 									//�ж��������i���ڵ���10�����Nice�� 
	{
		printf("Nice!\n");						//�����������ж������û����� 
		printf("Nice again!");
	} 
	return 0;
}
