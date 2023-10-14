#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;
int w[N];

int main()
{
    int t = 0, n = 0, m = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &w[i]);
        }
        sort(&w[0], &w[m]);
        int sumw = 0;
        int i = 0;
        for (; i < m; i++)
            if (sumw + w[i] <= n)
                sumw += w[i];
            else
                break;
        printf("%d\n", i);
    }
    return 0;
}