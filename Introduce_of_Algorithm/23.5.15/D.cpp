#include <iostream>
#include <algorithm>
using namespace std;

struct TD
{
    int t;
    int d;
} td[110];

bool cmp(TD x, TD y)
{
    return x.d < y.d;
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    int n = 0;
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &td[i].t, &td[i].d);
        }
        sort(td, td + n, cmp);
        int pass = 0;
        int late = 0;
        for (int i = 0; i < n; i++)
        {
            pass += td[i].t;
            int late_temp = pass - td[i].d;
            if (late_temp > late)
                late = late_temp;
        }
        printf("%d\n", late);
    }
    return 0;
}