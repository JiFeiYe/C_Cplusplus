#include<stdio.h>
int main()
{
	int Year;
	int a;
	scanf("%d",&Year);
	if(Year >= 2001 && Year <= 2100)
	{
		if(Year < 2004)
		{
			printf("None");
		}
		else
		{
			for(int i = 2001;i <= Year;i ++)
			{
				if(i != 2100 )
				{
					a = i % 4;
					if(a == 0)
					{
						printf("%d\n",i);
					}
				}
			}
		}

	}
	else
	{
		printf("Invalid year!");
	}
	
	return 0;
}
