#include<stdio.h>

//�������
int *re(int *a) 
{
	//�Ƚϴ�С����λ
	//a[0]>a[1]>a[2] 
	int temp;
	if(a[1] > a[0])
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	if(a[2] > a[1])
	{
		temp = a[1];
		a[1] = a[2];
		a[2] = temp;
	}
	if(a[1] > a[0])
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	return a;
} 

//������ 
int main()
{
	int N1,N2,a[3],i;
	scanf("%d",&N1);
	

	int b,c,d;
	for(int j = 1; ;j ++)
	{
		//��ȡÿһλ�� 
		for(i = 0;N1 != 0;i ++)
		{
			a[i] = N1 % 10;
			N1 = N1 / 10;
		}
		re(a);
		b = a[0]*100 + a[1]*10 + a[2];		//�����
		c = a[2]*100 + a[1]*10 + a[0]; 		//С���� 
		d = b - c;
		printf("%d: %d - %d = %d\n",j,b,c,d);
		N1 = d;
		if(d == 495 || d == 0)
		{
			break;
		}
	}
	return 0; 
}
