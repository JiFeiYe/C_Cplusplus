#include <iostream>
#include <string.h>
using namespace std;

int ans[1111111];

int main()
{
    memset(ans, 0, 1111111);
    int n = 0, k = 0;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        ans[0] = 1;
        for (int i = 1; i <= n; i++) // ans[i] = ans[i-1] + ans[i-2] +...+ ans[i-k];
        {
            for (int j = 1; j <= k; j++)
            {
                if (i >= j)
                    ans[i] = (ans[i] + ans[i - j]) % 100003;
            }
        }
        cout << ans[n] << endl;
    }
    return 0;
}