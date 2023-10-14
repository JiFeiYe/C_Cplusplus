#include <iostream>
#include <string.h>
using namespace std;

int a[100][100];
int d[100][100] = {-1};
int N = 0;

int max(int a, int b)
{
    return a > b ? a : b;
}

int DP()
{
    for (int i = N - 2; i >= 0; i--)
        for (int j = i; j >= 0; j--)
            d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
    return d[0][0];
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    memset(d, -1, 10000); // int类型只能0或-1
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) // i行i列
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &a[i][j]);
                if (i == N - 1)
                    d[i][j] = a[i][j];
            }
        printf("%d\n", DP());
    }
}