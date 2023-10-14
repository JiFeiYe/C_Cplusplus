#include <iostream>
#include <algorithm>
using namespace std;

int n;
int record[110];
int cnt[110];
int a[110];

void DFS(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
            printf(" %d" + !i, record[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!i || a[i] != a[i - 1])
        {
            int c1 = 0, c2 = 0;
            for (int j = 0; j < cur; j++)
                if (record[j] == a[i])
                    c1++;
            for (int j = 0; j < n; j++)
                if (a[j] == a[i])
                    c2++;
            if (c1 < c2)
            {
                record[cur] = a[i];
                DFS(cur + 1);
            }
        }
    }
}

int main()
{
    freopen("D:\\CODE\\Visual_Studio_Code_Introduce_of_Algorithm\\23.5.29\\out.txt", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < 110; i++)
        {
            a[i] = 1000000;
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        sort(&a[0], &a[n]);
        DFS(0);
    }
    fclose(stdout);
    return 0;
}