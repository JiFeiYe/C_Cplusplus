#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int N = 1e5 + 10;
struct Point
{
    double x;
    double y;
    int num;
} a[N], b[N], c[2]; // a存放所有点且排序后不用动，b存放a分治结果的部分点并排序，c存放最终结果

bool cmp(Point a, Point b)
{
    if (a.x > b.x)
        return false;
    else if (a.x < b.x)
        return true;
    else
    {
        if (a.y > b.y)
            return false;
        else
            return true;
    }
}
bool cmp_y(Point a, Point b)
{
    return a.y < b.y;
}
double dis(Point a, Point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double solve(int l, int r, int &index_a, int &index_b)
{
    if (l == r)
        return 0x3f3f3f;
    if (l + 1 == r)
    {
        if (dis(c[0], c[1]) > dis(a[l], a[r]))
        {
            c[0] = a[l];
            c[1] = a[r];
            index_a = min(a[l].num, a[r].num);
            index_b = max(a[l].num, a[r].num);
        }
        return dis(a[l], a[r]); // 两点相邻
    }
    int mid = (l + r) >> 1;
    double d = min(dis(c[0], c[1]),min(solve(l, mid, index_a, index_b), solve(mid + 1, r, index_a, index_b)));
    int k = 0;
    for (int i = l; i <= r; i++)
        if (fabs(a[i].x - a[mid].x) < d)
            b[++k] = a[i];
    sort(b + 1, b + 1 + k, cmp_y); // b数组按y排序
    for (int i = 1; i < k; i++)
        for (int j = i + 1; j <= k && b[j].y - b[i].y < d; j++)
            if (d > dis(b[i], b[j]))
            {
                d = dis(b[i], b[j]);
                c[0] = b[i];
                c[1] = b[j];
                index_a = min(a[l].num, a[r].num);
                index_b = max(a[l].num, a[r].num);
            }
    return d;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1, j = 0; i <= n; i++) // 从1开始方便标号
        {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            a[i].num = j++;
        }
        c[1].x = 30000;
        c[1].y = 40000;
        sort(a + 1, a + 1 + n, cmp); // 左开右闭
        int index_a = 0, index_b = 0;
        solve(1, n, index_a, index_b);
        printf("%d %d\n", index_a, index_b);
    }
    return 0;
}