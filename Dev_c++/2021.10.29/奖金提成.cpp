#include<stdio.h>
int main()
{
	int profit,bonus;				//profit:ÀûÈó£»bonus:½±½ğ
	int a,T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i ++)
	{
		scanf("%d",&profit);
		a = profit / 10000;
		switch(a)
		{
			case 0: bonus = profit * 0.1;					//profit<=10000
			break;
			case 1: bonus = 1000 + (profit - 10000) * 0.075;			//10000<profit<=20000
			break;
			case 2: case 3: bonus = 1750 + (profit - 20000) * 0.05;			//20000<profit<=40000
			break;
			case 4: case 5: bonus = 2750 + (profit - 40000) * 0.03;			//40000<profit<=60000
			break;
			case 6: case 7: case 8: case 9: bonus = 3350 + (profit - 60000) * 0.015;		//60000<profit<=100000
			break;
			default: bonus = 3950 + (profit - 100000) * 0.01; 		//profit>100000
			break;
		}	
		printf("%d\n",bonus);
	}
	
	return 0;
} 
