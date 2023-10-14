#include <iostream>
using namespace std;

const int N = 1e7 + 10;
int a[N];

int lowerbound(int begin, int end, int test)
{
    int mid = 0;
    int index = -1;
    while (begin < end)
    {
        mid = (begin + end) / 2;
        if (a[mid] >= test)  // 左转，不包含
            end = mid;
        else
            begin = mid + 1; // 右转，包含
    }
    return begin;
}

int main()
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int test = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &test);
        printf("%d\n", lowerbound(0, n, test) + 1);
    }
    return 0;
}