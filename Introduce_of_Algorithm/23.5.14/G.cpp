#include <iostream>
using namespace std;

int d[110][110];

int main()
{
    int m = 0, n = 0;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                    d[i][j]=1;
                else
                    d[i][j]=d[i-1][j]+d[i][j-1];
            }
        }
        printf("%d", d[m-1][n-1]);
    }
    return 0;
}
