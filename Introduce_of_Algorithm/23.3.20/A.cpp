#include <iostream>
using namespace std;

long long Solve(int x, int n)
{
    long long num = 1;
    for (int i = 0; i < n; i++)
    {
        num += num * x;
    }
    return num;
}

int main()
{
    long long x = 0, n = 0;
    while (scanf("%lld%lld", &x, &n) != EOF)
    {
        printf("%lld", Solve(x, n));
    }
    return 0;
}