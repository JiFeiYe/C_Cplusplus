/*
#include<stdio.h>
int main()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	int T = 0, count = 0;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		count = 0;
		scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf_s("%d%d%d%d", &x3, &y3, &x4, &y4);
		for (int j = x1; j <= x2; j++)//取其中一个矩形内一点
		{
			for (int k = y1; k <= y2; k++)
			{
				if (j >= x3 && j <= x4 && k >= y3 && k <= y4)
				{
					count++;
					printf("YES\n");
					break;
				}
			}
			if (count != 0)
			{
				break;
			}
		}
		if (count == 0)
		{
			printf("NO\n");
		}
//////////////////////////////////////////////////////////////////////////////////////////
//		for (int j = x1 > x3 ? x3 : x1; j <= x2 > x4 ? x2 : x4; j++)//j是从x2到x4从小到大
//		{
//			for (int k = y1 > y3 ? y3 : y1; j <= y2 > y4 ? y2 : y4; k++)
//			{
//
//			}
//		}
//
//
//		if (x1 >= x3 && x1 <= x4 && y1 <= y3 && y1 >= y4
//			|| x2 >= x3 && x2 <= x4 && y1 <= y3 && y1 >= y4
//			|| x1 >= x3 && x1 <= x4 && y2 <= y3 && y2 >= y4
//			|| x2 >= x3 && x2 <= x4 && y2 <= y3 && y2 >= y4)
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
///////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;
}
*/