#include<iostream>
#include<queue>
using namespace std;
const int maxN = 1100;
bool visit[maxN];
int dis[maxN];
typedef pair <int,int> pii;
priority_queue<pii , vector <pii> , greater <pii> > q;

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
    for(int i = 0; i < maxN; i++)
    {
        head[i] = -1;//head初始化为-1，主要取head[0]=-1
        visit[i] = false;//visit记录是否访问过某节点
        dis[i] = 0x3f3f3f;
    }
    dis[0] = 0;
}

void AddEdge(int u, int v, int w)//加边函数
{
    e[tp].set(v, w, head[u]);
    //以u为起点的上一条边的编号赋值给nex
    head[u] = tp++;
    //按顺序给每一条边编号
    //head[u]是以u为起点的最后一条边的编号
}

int ans = 0;
int count = 0;
void prim(int n)
{
    q.push(make_pair(0, 1));
    while(!q.empty() && count < n)
    {
        int d = q.top().first;//边权
        int u = q.top().second;//点
        q.pop();
        if(visit[u])
            continue;
        ans += d;//最终答案
        count++;//计数，用于判断是否遍历完整
        visit[u] = true;
        for(int i = head[u]; i!=-1; i = e[i].nex)
            if(e[i].w < dis[e[i].to])
            {
                dis[e[i].to] = e[i].w;
                q.push(make_pair(e[i].w, e[i].to));
            }
    }
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
    int n, m;//n点的数量，m边的数量
    int u, v, w;
    cin >> n >> m;
    Init();
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    prim(n);
    //display(n);
    n == count? cout << ans << endl : cout << "orz" << endl;
    return 0;
}