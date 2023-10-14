#include<iostream>
using namespace std;
const int MaxN = 20;//最大顶点数
const int INF = 0x3f3f3f;//无穷大
int dist[MaxN];//存放当前顶点距离S集合的最近距离，S集合用Map中的Visit数组表示
int p[MaxN];//存放当前顶点的前驱，可用于记录最短路径，初始化-1表示没有前驱（不可到达）

class Map
{
    int Matrix[MaxN][MaxN];//邻接矩阵
    int Vexnum;
    bool Visit[MaxN];
public:
    Map(int n, int mx[MaxN][MaxN]); 
    void Init(int u);
    void Dijkstra(int u);//u作为起点
    void Print();
};
Map::Map(int n, int mx[MaxN][MaxN])
{
    Vexnum = n;
    for(int i = 0; i < MaxN; i++)
    {
        for(int j = 0; j < MaxN; j++)
            Matrix[i][j] = 0;
    }
    for(int i = 1; i <= Vexnum; i++)
    {
        for(int j = 1; j <= Vexnum; j++)
            Matrix[i][j] = mx[i][j];
    }
    return;
}
void Map::Init(int u)
{
    for(int i = 1; i <= Vexnum; i++)
    {
        dist[i] = Matrix[u][i];
        Visit[i] = false;
        if(dist[i] == INF)
            p[i] = -1;
        else
            p[i] = u;
    }
}
void Map::Dijkstra(int u)//从u点出发到其他各顶点最短路径
{
    this->Init(u);
    dist[u] = 0;//自己到自己的距离是0
    Visit[u] = true;//u顶点放到S集合中
    //开始找最小、松弛循环
    //重复n-1次，每次重复包含找最小循环和松弛循环
    for(int i = 1; i < Vexnum; i++)//循环n-1次
    {
        int min = INF;//记录最小值
        int minV = u;//记录最小顶点下标
        for(int j = 1; j <= Vexnum; j++)//寻找V-S集合中的dist最小值
        {
            if(!Visit[j] && dist[j] < min)
            {
                min = dist[j];
                minV = j;
            }
        }
        if(minV == u)
            return;
        Visit[minV] = true;
        for(int j = 1; j <= Vexnum; j++)//判断借min_index松弛dist[]
        {
            if(!Visit[j] && dist[j] > dist[minV] + Matrix[minV][j])
            {
                dist[j] = dist[minV] + Matrix[minV][j];
                p[j] = minV;
            }
        }
    }
}
void Map::Print()
{
    for(int i = 1; i <= Vexnum; i++)
    {
        for(int j = 1; j <= Vexnum; j++)
        {
            if(Matrix[i][j] == INF)
            cout << "0 ";
            else
                cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "dist[]:" << endl;
    for(int i = 1; i <= Vexnum; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl << "p[]:" << endl;
    for(int i = 1; i <= Vexnum; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int n = 0;
    cin >> n;
    int mx[MaxN][MaxN];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> mx[i][j];
            if(mx[i][j] == 0)
                mx[i][j] = INF;
        }
    }
    Map m(n, mx);
    m.Dijkstra(1);
    m.Print();
    return 0;
}