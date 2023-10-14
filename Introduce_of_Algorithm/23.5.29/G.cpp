#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 20;
int tm[N][N], n, ans;
bool vis[N];
void DFS(int cur, int nowsum)
{
    if (nowsum >= ans)
        return;
    if (cur == n)
    {
        ans = std::min(ans, nowsum);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        DFS(cur + 1, nowsum + tm[cur][i]);
        vis[i] = false;
    }
}
int main()
{
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &tm[i][j]);
    ans = 1e9;
    DFS(0, 0);
    printf("%d\n", ans);
    return 0;
}