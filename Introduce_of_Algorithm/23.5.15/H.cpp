#include <iostream>
#include <algorithm>
using namespace std;

struct IR
{
    long long i;
    long long r;
} ir[110];

struct machine
{
    long long i;
    long long r;
} ma[110];

bool cmp(IR x, IR y)
{
    return x.i < y.i;
}

bool cmp_(machine x, machine y)
{
    return x.r > y.r;
}

int main()
{
    long long t = 0;
    scanf("%lld", &t);
    long long n = 0;
    while (t--)
    {
        scanf("%lld", &n);
        for (long long j = 0; j < n; j++)
        {
            scanf("%lld%lld", &ir[j].i, &ir[j].r);
        }
        sort(ir, ir + n, cmp);
        long long num = 0;
        for (long long i = 0; i < n; i++)
        {
            long long flag = 0;
            for (long long j = 0; j < num; j++)
            {
                if (ir[i].i >= ma[j].r) // 机器空闲
                {
                    flag = 1;
                    ma[j].r = ir[i].r; // 空闲时间也要算进去
                    break;
                }
            }
            if (!flag)
            {
                num++; // 加一台机器
                ma[num - 1].i = ir[i].i;
                ma[num - 1].r = ir[i].r;
            }
            sort(ma, ma + num, cmp_);
        }
        long long sum = 0;
        for (long long j = 0; j < num; j++)
        {
            sum += ma[j].r - ma[j].i;
        }
        printf("%lld %lld\n", num, sum);
    }
    return 0;
}