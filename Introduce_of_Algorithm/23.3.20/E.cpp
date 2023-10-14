#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

long long a[1010];

int main()
{
    memset(a, 0, 1010);
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++) // 下标从1开始
        {
            scanf("%lld", &a[i]);
        }
        long long min = 10000000000000000;
        int index1 = 0, index2 = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (j != i && abs(a[i] + a[j]) < min)
                {
                    min = abs(a[i] + a[j]);
                    index1 = i;
                    index2 = j;
                }
            }
        }
        printf("%d %d\n", index1, index2);
    }
    return 0;
}