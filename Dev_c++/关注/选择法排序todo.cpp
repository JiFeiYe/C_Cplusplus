#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	double a[T];
	
	
	//为数组赋值 
	for(int i = 0;i < T;i ++)
	{
		printf("a[%d]=",i);
		scanf("%lf",&a[i]);
	}
	
	//选择法从小到大排序 
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
		//交换数值位置 
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
