/*
#include<stdio.h>
#include<math.h>

//统计number中digit的个数
int countdigit(int number, int digit)
{
	int count = 0, text = 0;
	number = fabs(number);
	if (number == 0)
	{
		count++;
	}
	else
	{
		while (number != 0)
		{
			text = number % 10;
			if (text == digit)
			{
				count++;
			}
			number = number / 10;
		}
	}
	return count;
}

int main()
{
	int number = 0, digit = 0, count = 0;
	scanf_s("%d%d", &number, &digit);
	printf("Number of digit %d in %d: ", digit, number);
	count = countdigit(number, digit);
	printf("%d", count);
	return 0;
}
*/