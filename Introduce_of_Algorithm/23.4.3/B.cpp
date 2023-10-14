// 快速幂
#include <iostream>
using namespace std;

int PowMod(int a, int b, int p)
{
    int ans = 1;
    for(; b; b >>= 1, a = 1LL * a * a % p)
        if(b & 1)
            ans = 1LL * ans * a % p;
    return ans;
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    int a = 0, b = 0, p = 0;
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", PowMod(a, b, p));
    }
    return 0;
}