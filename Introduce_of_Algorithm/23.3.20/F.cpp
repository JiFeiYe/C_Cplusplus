#include <iostream>
using namespace std;

long long a[1000011];
long long Sumf[1000011];

int main()
{
    long long n = 0, m = 0;
    scanf("%lld%lld", &n, &m);
    a[0] = 0, Sumf[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        Sumf[i] = Sumf[i - 1] + a[i]; // 求前缀和
    }
    long long l = 0, r = 0;
    for (long long i = 0; i < m; i++)
    {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", Sumf[r] - Sumf[l - 1]);
    }
    return 0;
}  