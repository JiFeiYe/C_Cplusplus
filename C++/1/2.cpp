#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int judge(int a) // 素数判断
{
    for (int i = 2; i < sqrt(a); i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a = 0;
    scanf("%d", &a);
    if (judge(a))
        printf("%d\n", a);
    else
    {
        for (int i = a/2; i >= 2; i--)
            if (a % i == 0)
            {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}