#include<iostream>
using namespace std;
const int MaxLen = 20;

class Map
{
    int Matrix[MaxLen][MaxLen];//邻接矩阵
    int Vexnum;//节点数
    bool Visit[MaxLen];//是否访问过该节点
    int count = 0;
    int ind[MaxLen];//统计入度
public:
    void Init(int n, int mx[MaxLen][MaxLen]);
    void DFS(int vex);
    void TopoSort();
    friend void printMatrix(Map m);
};
void Map::Init(int n, int mx[MaxLen][MaxLen])//初始化matrix与visit
{
    count = 0;
    Vexnum = n;
    for(int i = 0; i < MaxLen; i++)
    {
        Visit[i] = false;
        for(int j = 0; j < MaxLen; j++)
            Matrix[i][j] = 0;
    }
    for(int i = 0; i < Vexnum; i++)
        for(int j = 0; j < Vexnum; j++)
            Matrix[i][j] = mx[i][j];
}
void Map::DFS(int vex)//DFS算法
{
    if(Visit[vex]) return;
    Visit[vex] = true;
    count ++;
    for(int i = 0; i < Vexnum; i++)
        if(Matrix[vex][i])
            DFS(i);
}
void Map::TopoSort()
{
    int j = 0, rtp = 0;
    for(int i = 0; i < Vexnum; i++)
        ind[i] = 0;
    for(int i = 0; i < Vexnum; i++)
        for(j = 0; j < Vexnum; j++)
            ind[j] += Matrix[i][j];//统计入度
    for(int i = 0; i < Vexnum; i++)
    {
        for(j = 0; j < Vexnum && ind[j]; j++);//寻找一个入度为0的顶点
        cout << j << " ";
        ind[j] = -1;
        for(int k = 0; k < Vexnum; k++)
            ind[k] -= Matrix[j][k];
    }
}

void printMatrix(Map m)//调试用
{
    cout << endl;
    for(int i = 0; i < m.Vexnum; i++)
    {
        for(int j = 0; j < m.Vexnum; j++)
        {
            cout << m.Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int k = 0;
    cin >> k;
    int n = 0;
    while(k--)
    {
        cin >> n;
        int matrix[MaxLen][MaxLen] = {0};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Map m;
        m.Init(n, matrix);
        m.TopoSort();
        cout << endl;
        //printMatrix(m);//用于调试
    }
    return 0;
}