#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	double a[T];
	
	
	//Ϊ���鸳ֵ 
	for(int i = 0;i < T;i ++)
	{
		printf("a[%d]=",i);
		scanf("%lf",&a[i]);
	}
	
	//ѡ�񷨴�С�������� 
	double iMin,iIn; 
	for(int i = 0;i < T-1;i ++)
	{
		iMin = a[i];
		for(int j = i+1;j < T;j ++)
		{
			if(iMin > a[j])
			{
				iMin = a[j];
			} 
		}
		//������ֵλ�� 
		double iTemp;
		iTemp = a[i];
		a[i] = iMin;
	} 
	for(int i = 0;i < T;i ++)
	{
		printf("%f\n",a[i]);
	}

	
	
	
	
	return 0;
}
