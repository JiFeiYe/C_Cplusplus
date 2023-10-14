#include <iostream>
#include <cstring>
using namespace std;

char a[1010];
char b[1010];
int d[1010][1010];

int max1(int a_, int b_)
{
    return a_ > b_ ? a_ : b_;
}

void swap(int &a_, int &b_)
{
    a_ = a_ ^ b_;
    b_ = a_ ^ b_;
    a_ = a_ ^ b_;
}

int main()
{
    a[0] = ' ', b[0] = ' ';
    while (scanf("%s%s", &*(a+1), &*(b+1)) != EOF)
    {
        int alen = strlen(a);
        int blen = strlen(b);
        for (int i = 1; i < alen; i++)
        {
            for (int j = 1; j < blen; j++)
            {
                if (a[i] == b[j])
                    d[i][j] = d[i - 1][j - 1] + 1;
                else
                    d[i][j] = max1(d[i][j - 1], d[i - 1][j]);
            }
        }
        printf("%d\n", d[alen-1][blen-1]);
    }
    return 0;
}