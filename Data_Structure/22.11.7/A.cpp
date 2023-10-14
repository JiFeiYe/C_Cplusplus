#include<iostream>
using namespace std;
const int MaxN = 20;//最大顶点数
const int INF = 0x3f3f3f;//无穷大
int dist[MaxN];//存放当前顶点距离源点的最短距离，S集合用Map中的Visit数组表示
int p[MaxN];//存放当前顶点的前驱，可用于记录最短路径，初始化-1表示没有前驱（不可到达）
string str[MaxN];//存放顶点名字，从1开始

class Map
{
    int Matrix[MaxN][MaxN];//邻接矩阵
    int Vexnum;
    bool Visit[MaxN];
public:
    Map(int n, int mx[MaxN][MaxN]); 
    void Init(int u);
    void Dijkstra(int u);//u作为起点
    void findp(int u);//被查找点u（非源点）
    void FindPath(int u);//源点u
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
void Map::findp(int u)//递归输出源点到u的最短路径
{
    if(u == -1)
        return;
    findp(p[u]);
    cout << str[u] << " ";
}
void Map::FindPath(int u)
{
    for(int i = 2; i <= Vexnum; i++)
    {
        if(dist[i] == INF)
        {
            cout << str[u] << "-" << str[i] << "-" << "-1"<< endl;
        }
        else
        {
            cout << str[u] << "-" << str[i] << "-" << dist[i] << "----[";
            findp(i);
            cout << "]" << endl;
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
    int t = 0;
    cin >> t;
    int n = 0;

    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)//全文代码i、j均是从1开始
        {
            cin >> str[i];
        }
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
        string temp = str[1];//取第一个做样例
        int flag = 0;
        char ch = ' ';
        if(temp.length() == 1)
        {
            flag = 0;
            ch = temp[0];
        }
        else if(temp.length() == 2)
        {
            flag = 1;
            ch = temp[1];
        }
        string start;
        cin >> start;
        int start_;
        if(flag)
            start_ = start[1] - ch;
        else
            start_ = start[0] - ch;
        m.Dijkstra(start_ + 1);
        m.FindPath(start_ + 1);
        //m.Print();
    }
    
    return 0;
}