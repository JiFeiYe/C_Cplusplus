#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", 2 * n / 3 + 1);
	// 每3个棒子换一根新的冰棍,相当于2个棒子换一个不带棒子的冰棍，因此买的冰棍数乘以3/2再向下取整就是能吃到的冰棍数量
	return 0;
}