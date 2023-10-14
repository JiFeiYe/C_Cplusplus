#include<iostream>
#include<queue>
using namespace std;

const int MaxLen = 20;

class Map
{
private:
    bool Visit[MaxLen];
    int Matrix[MaxLen][MaxLen];
    int Vexnum;
    void BFS(int v);
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void BFSTraverse();
};
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i, j;
    Vexnum = vnum;
    for (i = 0; i < MaxLen; i++)
        for (j = 0; j < MaxLen; j++)
            Matrix[i][j] = 0;
    for (i = 0; i < vnum; i++)
    {
        Visit[i] = false;
        for (j = 0; j < vnum; j++)
            Matrix[i][j] = mx[i][j];
    }
}
void Map::BFSTraverse()
{
    BFS(0);
}
void Map::BFS(int v)
{
    int now = 0;
    queue <int> Q;
	Visit[v] = true;
	cout << v << " ";
    Q.push(v);
    while(!Q.empty())
    {
		now = Q.front();
        Q.pop();
        for(int i = 0; i < Vexnum; i++)
        {
			if(Matrix[now][i] && !Visit[i])
            {
                Visit[i] = true;
                cout << i << " ";
                Q.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    while(t--)
    {
        cin >> n;
        int matrix[MaxLen][MaxLen];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
    	Map m;
        m.SetMatrix(n, matrix);
        m.BFSTraverse();    
    }
    return 0;
}