/*
#include<stdio.h>

int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return  fib(n - 1) + fib(n - 2);
	}
}

void print_fn(int m, int n) {
	int count = 0;
	for (int i = 1; i <= 21; i++) {
		if (fib(i) >= m && fib(i) <= n) {
			printf("%d ", fib(i));
			count++;
			continue;
		}
	}
	if(count == 0){
		printf("No Fibonacci number");
	}
}

int main() {
	int m = 0, n = 0;
	scanf_s("%d%d", &m, &n);
	print_fn(m, n);
	return 0;
}
*/