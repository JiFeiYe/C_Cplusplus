//¸çµÂ°ÍºÕ²ÂÏë
#include <stdio.h>
#include <math.h>
int prime(int p);
void g(int m , int n);

int main()
{
	int m = 0, n = 0;
	scanf_s("%d %d", &m, &n);
	g(m, n);
	return 0;

}

int prime(int p)
{
	int i = 0, limit = 0;
	if (p == 1) {
		return 0;
	}
	else if (p == 2)
	{
		return 1;
	}

	else
	{
		limit = sqrt(p) + 1;
		for (i = 2; i <= limit; i++) {
			if (p % i == 0) {
				break;
			}
		}
		if (i > limit)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void g(int m, int n)
{
	int i = 0, count = 0, k = 0;
	for (k = m; k <= n; k++) {
		if (k % 2 == 0) {
			for (i = 2; i < (k / 2); i++) {
				if ((prime(i) == 1) && (prime(k - i) == 1)) {
					printf("%d=%d+%d", k, i, k - i);
					count++;
					if (count % 5 == 0 && count != 0) {
						printf("\n");
					}
					else {
						printf(", ");
					}
					break;
				}
			}
		}
	}
	
	return;
}