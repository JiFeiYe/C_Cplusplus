#include<stdio.h>
//主函数 
int main()
{
	int N1,N2,a[3],i;
	scanf("%d",&N1);
	
	int b,c,d;
	for(int j = 1; ;j ++)
	{
		//提取每一位数 
		for(i = 0;N1 != 0;i ++)
		{
			a[i] = N1 % 10;
			N1 = N1 / 10;
		}
		if(a[1] == a[2] && a[2] == a[0])
		{
			goto here;			
		} 
		//排序 
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
		here:
		b = a[0]*100 + a[1]*10 + a[2];		//大的数
		c = a[2]*100 + a[1]*10 + a[0]; 		//小的数 
		d = b - c;							//大减小 
		printf("%d: %d - %d = %d\n",j,b,c,d);
		N1 = d;
		if(d == 495 || d == 0)
		{
			break;
		}
	}
	return 0; 
}
