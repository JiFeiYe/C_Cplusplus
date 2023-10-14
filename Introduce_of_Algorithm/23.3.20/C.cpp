#include <iostream>
#include <string.h>
using namespace std;

int num[1010];
int main()
{

    int n = 0;
    while (cin >> n)
    {
        memset(num, 0, 1010);
        num[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            num[i] = i / 2;
            for (int j = 1; j <= i / 2; j++)
            {
                num[i] += num[j];
            }
        }
        cout << num[n]+1 << endl;
    }
    return 0;
}