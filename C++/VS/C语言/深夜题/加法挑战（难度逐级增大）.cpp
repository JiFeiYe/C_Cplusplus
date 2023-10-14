#include<stdio.h>
#include<string.h>

void Sum(char* ch1, char* ch2, char* sum)
{
	ch1 = strrev(ch1);
	ch2 = strrev(ch2);
	int len1 = strlen(ch1), len2 = strlen(ch2), len3 = 0;
	len3 = len1 >= len2 ? len1 : len2;
	int sign = 0, temp = 0;
	for (int i = 0; i <= len3; i++)
	{
		temp = ((ch1[i] + '0') + (ch2[i] + '0')) + sign;
		sum[i] += temp % 10 + ' ';
	}
	sum = strrev(sum);
	printf("%s", sum);
	return;
}

int main()
{
	char ch1[50] = { ' ' }, ch2[50] = { ' ' }, sum[50] = { ' ' };
	scanf_s("%s", ch1, 50);
	scanf_s("%s", ch2, 50);
	Sum(ch1, ch2, sum);
	return 0;
}