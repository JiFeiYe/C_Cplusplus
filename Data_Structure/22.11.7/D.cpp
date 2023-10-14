#include<iostream>
#include<queue>
using namespace std;
const int MaxN = 20;//最大顶点数
int dist[MaxN];
// typedef pair <int,int> pii;
// priority_queue<pii, vector<pii>, greater<pii>> q;

class Map
{
    int Matrix[MaxN][MaxN];//邻接矩阵
    int Vexnum;
    bool Visit[MaxN];
public:
    Map(int n, int mx[MaxN][MaxN]); 
    void Init();
    int prim(int n);
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
void Map::Init()
{
    for(int i = 0; i < MaxN; i++)
    {
        Visit[i] = false;
        dist[i] = 0x3f3f3f;
    }
    for(int i = 2; i <= Vexnum; i++)
    {
        dist[i] = Matrix[1][i];
    }
}
long long sum = 0;
int Map::prim(int vex)
{
    dist[vex] = 0;
    Visit[vex] = true;
    for(int i = 0; i <= Vexnum; i++)
    {
        int minindex = 1;
        int minv = 0x3f3f3f3f;
        for(int j = 1; j <= Vexnum; j++)
        {
            if(!Visit[j] && dist[j] < minv)
            {
                minindex = j;
                minv = dist[j];
            }
        }
        if(minindex == 1) return -1;
        Visit[minindex] = true;
        for(int k = 1; k <= Vexnum; k++)
        {
            if(!Visit[k] && Matrix[minindex][k] && Matrix[minindex][k] < dist[k])
            {
                dist[k] = Matrix[minindex][k];
            }
        }
    }
    //
    int Q = 0;
    cin >> Q;
    int a, b;
    for(int j = 1; j <= Vexnum; j++) sum += dist[j];
    while(Q--)
    {
        cin >> a >> b;
        sum -= Matrix[a][b];
    }
    return sum;
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
                mx[i][j] = 0x3f3f3f;
        }
    }
    Map m(n, mx);
    m.Init();
    int ans = m.prim(1);
    cout << ans << endl;
    return 0;
}