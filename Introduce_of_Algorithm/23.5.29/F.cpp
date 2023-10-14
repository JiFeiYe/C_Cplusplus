#include <iostream>
#include <math.h>
using namespace std;

int n = 0, k = 0, sum = 0, num = 0, tot = 0;
int a[30];

bool IsPrime(int x)
{
    for (int i = sqrt(x) + 1; i > 1; i--)
        if (x % i == 0)
            return false;
    return true;
}

void DFS(int cur)
{
    if (num == k)
    {
        if (IsPrime(sum))
            tot++;
        return;
    }
    if (cur == n)
        return;
    sum += a[cur];
    num ++;
    DFS(cur + 1);
    sum -= a[cur];
    num--;
    DFS(cur + 1);
}

int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sum = 0;
        num = 0;
        DFS(0);
        printf("%d\n", tot);
    }
    return 0;
}