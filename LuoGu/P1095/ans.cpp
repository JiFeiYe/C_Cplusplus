#include <bits/stdc++.h>

int main()
{
    int m = 0, s = 0, t = 0, t1 = 0;
    int ans = 0;
    int flag = 0;
    while (scanf("%d%d%d", &m, &s, &t) != EOF)
    {
        t1 = t;
        flag = 0;
        ans = 0;
        while (t)
        {
            if (m >= 10)
            {
                ans = flag;
                m -= 10;
                ans += 60;
                flag = ans;
            }
            else
            {
                m += 4;    // 回蓝线
                ans += 17; // 走路线
            }
            if (ans >= s)
            {
                printf("Yes\n%d\n", t1 - t + 1);
                break;
            }
            t--;
        }
        if (t == 0)
        {
            printf("No\n%d\n", ans);
        }
    }
    return 0;
}
/*
251 6724 458
Yes
330(331?332?)
*/
