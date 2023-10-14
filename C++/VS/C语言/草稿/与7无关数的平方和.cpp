/*
#include<stdio.h>
#include<math.h>

int judge(int i) {
	for (int j = 1; j <= i; j *= 10) {
		if ((i / j) % 10 == 7) {
			return 1;
		}
	}
	if (i % 7 == 0) {
		return 1;
	}
	return 0;
}

int main() {
	int n = 0, judge_ = 0,  sum = 0;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		judge_ = judge(i);
		if (judge_ == 0) {
			sum += pow(i, 2);
		}
	}
	printf("%d", sum);
	return 0;
}
*/