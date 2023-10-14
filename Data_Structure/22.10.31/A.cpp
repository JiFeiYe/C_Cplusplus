#include<iostream>
using namespace std;

const int MaxLen = 20;

class Map
{
    int Matrix[MaxLen][MaxLen];
    int Vexnum;
    bool Visit[MaxLen];
    int count = 0;
public:
    void Init(int n, int mx[MaxLen][MaxLen]);
    void DFS(int vex);
    bool SFD();
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
bool Map::SFD()//如果深度优先正着能走完所有点，那么就可以反着来走一遍
{
    DFS(0);
    if(count != Vexnum) return false;
    for(int i = 0; i < Vexnum; i++)//将所有单向边反向
    {
        for(int j = 0; j <= i; j++)
        {
            if(Matrix[i][j] == 1 && Matrix[j][i] == 0)
            {
                Matrix[i][j] = 0;
                Matrix[j][i] = 1;
            }
            else if(Matrix[i][j] == 0 && Matrix[j][i] == 1)
            {
                Matrix[i][j] = 1;
                Matrix[j][i] = 0;
            }
        }
    }
    count = 0;
    for(int i = 0; i < MaxLen; i++)
        Visit[i] = false;
    DFS(0);
    if(count != Vexnum) return false;
    return true;
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
        if(m.SFD())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        //printMatrix(m);//用于调试
    }
    return 0;
}