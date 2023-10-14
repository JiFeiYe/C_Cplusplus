#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int N = 12;
double te[N], r[N], ans;
int n, th[N];
inline double Sqr(double x) { return x * x; }
void DFS(int status, double redge)
{
    int nownum = __builtin_popcount(status);
    int cur = th[nownum - 1];
    if (nownum == n)
    {
        ans = min(ans, redge);
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (status >> i & 1)
            continue;
        double nsite = r[i];
        double tmpredge = redge;
        for (int j = 0; j < nownum; j++)
            nsite = max(nsite, te[j] + sqrt(Sqr(r[th[j]] + r[i]) - Sqr(r[th[j]] - r[i])));
        tmpredge = max(tmpredge, nsite + r[i]);
        th[nownum] = i;
        te[nownum] = nsite;
        DFS(status | 1 << i, tmpredge);
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        ans = 1e20;
        th[0] = te[0] = r[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lf", &r[i]);
        n++;
        DFS(1, 0);
        printf("%.3f\n", ans);
    }
    return 0;
}