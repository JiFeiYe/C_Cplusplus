#include <iostream>
#include <string.h>
using namespace std;

const int N = 2020;
int a[N];

int main()
{
    memset(a, 0, N);
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    int test;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &test);
        a[test + 1000] += 1; // 加一千直接当下标用
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &test); // test -> k 当下标用
        int count = 0;
        for (int j = 1; j <= test + 1000; j++)
            count += a[j];
        printf("%d\n", n - count);
    }
    return 0;
}