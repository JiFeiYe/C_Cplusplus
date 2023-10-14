//#include<iostream>
//using namespace std;
//
//const int MaxLen = 20;
//
//class Map
//{
//private:
//    bool Visit[MaxLen];
//    int Matrix[MaxLen][MaxLen];
//    int Vexnum;
//    void DFS(int v);
//public:
//    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
//    void DFSTraverse();
//};
//void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
//{
//    int i, j;
//    Vexnum = vnum;
//    for (i = 0; i < MaxLen; i++)
//        for (j = 0; j < MaxLen; j++)
//            Matrix[i][j] = 0;
//    for (i = 0; i < vnum; i++)
//        for (j = 0; j < vnum; j++)
//            Matrix[i][j] = mx[i][j];
//}
//void Map::DFSTraverse()
//{
//    int v;
//    for (v = 0; v < MaxLen; v++)
//        Visit[v] = false;
//    for (v = 0; v < Vexnum; v++)
//    {
//        if (!Visit[v])
//            DFS(v);
//    }
//    cout << endl;
//}
////深度优先搜索
//void Map::DFS(int v)
//{
//    int w = 0, i = 0, k = 0;
//    Visit[v] = true;
//    cout << v << " ";//访问结点
//    int* AdjVex = new int[Vexnum];
//    for (i = 0; i < Vexnum; i++)//初始化-1
//        AdjVex[i] = -1;
//    k = 0;
//    for (i = 0; i < Vexnum; i++)//通过邻接矩阵写入AdjVex
//    {
//        if (Matrix[v][i])
//            AdjVex[i] = i;
//    }
//    i = 0;
//    while (w != -1)
//    {
//        w = AdjVex[i];
//        if (!Visit[w])
//            DFS(w);
//        else
//            i++;
//    }
//    delete[]AdjVex;
//}
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    int n = 0;
//    while (t--)
//    {
//        int matrix[MaxLen][MaxLen];
//        cin >> n;
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j < n; j++)
//                cin >> matrix[i][j];
//        Map m;
//        m.SetMatrix(n, matrix);
//        m.DFSTraverse();
//    }
//    return 0;
//}