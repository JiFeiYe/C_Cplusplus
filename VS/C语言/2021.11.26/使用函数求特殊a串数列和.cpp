/*
#include<stdio.h>
#include<math.h>

int fn(int a,int n) {
	int j = 0;
	for (int i = 1; i <= pow(10,n-1); i *= 10) {
		j += a * i;
	}
	return j;
}
int main() {
	int a = 0, n = 0, sum = 0;
	scanf_s("%d%d", &a, &n);
	for (int i = 1; i <= n; i++) {
		sum += fn(a, i);
	}
	printf("fn(%d, %d) = %d\n", a, n, fn(a, n));
	printf("s = %d", sum);
	return 0;
}
*/