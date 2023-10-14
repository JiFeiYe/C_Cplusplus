#include <iostream>
using namespace std;

int g[20][20];
int color[20];
int n, m, q, ans;

int conflict(int k, int col)
{
    for (int i = 1; i < k; i++)
    {
        if (g[i][k] && color[i] == col)
            return 1;
    }
    return 0;
}
void dfs(int cur)
{
    if (cur > n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (!conflict(cur, i))
        {
            color[cur] = i;
            dfs(cur + 1);
        }
    }
}

int main()
{
    int x, y;
    while (scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &x, &y);
            g[x][y] = 1;
            g[y][x] = 1;
        }
        dfs(1);
        printf("%d\n", ans);
    }
}