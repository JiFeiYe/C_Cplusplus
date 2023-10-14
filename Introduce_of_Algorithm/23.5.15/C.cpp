#include <iostream>
#include <algorithm>
using namespace std;

struct act
{
    int start;
    int end;
} a[10010];

bool cmp(act x, act y) // 选择结束时间最早的活动
{
    return x.end < y.end;
    // if (x.start < y.start)
    //     return true;
    // else if (x.start == y.start)
    //     if (x.end < y.end)
    //         return true;
    // return false;
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].start, &a[i].end);
        }
        sort(&a[0], &a[n], cmp);
        int num = 1;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            for (; j < n; j++)
            {
                if (a[i].end <= a[j].start)
                {
                    num++;
                    break;
                }
            }
            i = j;
        }
        printf("%d\n", num);
    }
    return 0;
}