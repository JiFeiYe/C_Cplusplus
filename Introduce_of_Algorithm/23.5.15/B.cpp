#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    double value;  // 单价
    double weight; // 重量
} a[1505];

bool cmp(item x, item y)
{
    return x.value < y.value;
}

int main()
{
    int t = 0, n = 0, m = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%lf%lf", &a[i].value, &a[i].weight);
        }
        sort(&a[0], &a[m], cmp);
        double sumweight = 0;
        for (int i = 0; i < m && n > 0; i++)
        {
            if (a[i].value * a[i].weight <= n)
            {
                sumweight += a[i].weight;
                n -= a[i].value * a[i].weight;
                continue;
            }
            else
            {
                sumweight += n / a[i].value;
                break;
            }
        }
        printf("%.2lf\n", sumweight);
    }
    return 0;
}