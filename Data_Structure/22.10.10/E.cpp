#include<iostream>
using namespace std;


void Tree(int *tree, int n, int i)//递归
{
    if(*tree != 0)
        cout << *tree << " ";//先序先输出再下一步
    if(2*i + 1 < n)//左2*i+1
        Tree(tree+i+1, n, 2*i+1);
    if(2*i + 2 < n)//右2*i+2
        Tree(tree+i+2, n, 2*i+2);
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int tree[1005];
        for(int i = 0; i < n; i++)
        {
            cin >> tree[i];
        }
        Tree(tree, n, 0);
        cout << endl;
    }
    return 0;
}