#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

struct Node
{
    int mat[2][2];
    Node() {}
    Node(int a_, int b_, int c_, int d_)
    {
        mat[0][0] = a_;
        mat[0][1] = b_;
        mat[1][0] = c_;
        mat[1][1] = d_;
    }
    // TODO: 矩阵乘法，注意取模
    Node operator*(const Node &y)
    {
        Node x(0, 0, 0, 0);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    x.mat[i][j] += 1LL * this->mat[i][k] * y.mat[k][j] % mod;
                }
                x.mat[i][j] %= mod;
            }
        }
        return x;
    }
};

// TODO: 矩阵的快速幂
Node Pow(Node a, int n)
{
    Node ans(1, 0, 0, 1);
    for (; n; n >>= 1, a = a * a)
        if (n & 1)
            ans = ans * a;
    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // TODO: 初始化用于推导斐波那契数列的矩阵
        Node x(1, 1, 1, 0);
        // TODO: 输出矩阵中对应的斐波那契第n项
        Node ans = Pow(x, n);
        printf("%d\n", ans.mat[0][1]);
    }
    return 0;
}