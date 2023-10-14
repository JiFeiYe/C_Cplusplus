#include <bits/stdc++.h>

int main()
{
    int k = 0;
    while (scanf("%d", &k) != EOF)
    {
        int sub1 = 0, sub2 = 0, sub3 = 0;
        int flag = 0;
        for (int i = 10000; i <= 30000; i++)
        {
            sub1 = i / 100;
            sub2 = (i % 10000) / 10;
            sub3 = i % 1000;
            if (sub1 % k == 0 &&
                sub2 % k == 0 &&
                sub3 % k == 0)
            {
                printf("%d\n", i);
                flag = 1;
            }
            if (i == 30000 && flag == 0)
                printf("No\n");
        }
    }
    return 0;
}