//前向星表示图
#include<iostream>
using namespace std;
const int maxN = 1100;

class Edge
{
public:
    int to, w, nex;//to终点，w边权
    //nex,表示与这个边起点相同的上一条边的编号
    void set(int v, int w_, int nex_)
    {
        to = v; w = w_; nex = nex_;
    }
}e[maxN];
int head[maxN];//head数组，表示以i为起点的最后一条边的编号
int tp;

void Init()
{
    tp = 0;
    for(int i = 0; i < maxN; i++)//head初始化为-1，主要取head[0]=-1
        head[i] = -1;
}

void AddEdge(int u, int v, int w)//加边函数
{
    e[tp].set(v, w, head[u]);
    //以u为起点的上一条边的编号赋值给nex
    head[u] = tp++;
    //按顺序给每一条边编号
    //head[u]是以u为起点的最后一条边的编号
}

void display(int n)
{
    for(int i = 1 ; i <= n; i++)
    {
        cout << i << endl;
        for(int j = head[i]; j != -1; j = e[j].nex)
        {
            cout << i << " " << e[j].to << " " << e[j].w << endl;
        }
        cout << endl;
    }
}

int main()
{
    int t = 0; 
    cin >> t;
    int n, m;//n点的数量，m边的数量
    int u, v, w;
    while(t--)
    {
        cin >> n >> m;
        Init();
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            AddEdge(u, v, w);
        }
        display(n);
    }
    return 0;
}