#include<stdio.h>
int main()
{
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	
	//�ж��Ƿ�Ϊ����
	int sum1,sum2; 
	if(year % 4 == 0 && year % 100 != 0)			//������ 
	{
		int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		//�����·�ǰ������ 
		for(int i = 1;i < month;i ++)
		{
			sum1 += b[i-1];
		}
		//����ó���� 
		sum2 = 366 - day - sum1;
	} 
	else				//�������� 
	{
		int b[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		//�����·�ǰ������ 
		for(int i = 1;i < month;i ++)
		{
			sum1 += b[i-1];
		} 
		//����ó���� 
		sum2 = 365 - day - sum1;
	} 
	printf("%d",sum2);
	
	return 0;
}
