/*
#include<stdio.h>

int fn(int n) {
	int count = 0, temp = 0, j = 0, k = 0;
	for (int i = 1; i <= n; i++) {
		j = i;
		k = n;
		while (k != 0) {
			temp =j % k;
			j = k;
			k = temp;
		}
		if (j == 1) {
			count++;
		}
	}
	return count;
}

int main() {
	int T = 0, n = 0, result = 0;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf_s("%d", &n);
		result = fn(n);
		printf("%d\n", result);
	}
	return 0;
}
*/