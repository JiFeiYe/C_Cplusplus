/*
#include<stdio.h>

int gcd(int m, int n);
int lcm(int gcd, int m, int n);

int main()
{
	int m = 0, n = 0, gcd_ = 0, lcm_ = 0;
	scanf_s("%d%d", &m, &n);
	gcd_ = gcd(m, n);
	printf("%d ", gcd_);
	lcm_ = lcm(gcd_,m, n);
	printf("%d", lcm_);
	return 0;
}

int gcd(int m, int n)
{
	int temp = 0;
	for (int i = 1; n != 0; i++)
	{
		temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}

int lcm(int gcd, int m, int n)
{
	int lcm_ = 0;
	lcm_ = m * n / gcd;
	return lcm_;
}
*/