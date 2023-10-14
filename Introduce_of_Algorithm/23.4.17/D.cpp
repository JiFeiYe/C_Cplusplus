#include <iostream>
using namespace std;

int item[1010][2];
int d[1010][10010];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n = 0, b = 0;
    while (scanf("%d%d", &n, &b) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &item[i][0], &item[i][1]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                d[i][j] = d[i - 1][j];
                if (j >= item[i][0])
                    d[i][j] = max(d[i][j - item[i][0]] + item[i][1], d[i-1][j]);
            }
        }
        printf("%d\n", d[n][b]);
    }
    return 0;
}