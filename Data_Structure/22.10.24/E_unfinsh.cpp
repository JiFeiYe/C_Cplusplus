#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adjMat;//领接矩阵
    int n;
    vector<bool> isVisited;
    void printAdjMat()//用于调试
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cout << adjMat[i][j] << " ";
        cout << endl;
    }
    void readAdjMat()
    {
        cin >> this->n;
        for(int i = 0; i < n; i++)
        {
            //todo:将false增加到isVisited数组，表示定点i没有访问过
            vector<int> row;
            for(int j = 0; j < n; j++)
            {
                int edge;
                //todo:将[i,j]的边信息（0或1）读入变量edge中
                //todo:将edge增加到row的末尾
            }
            //todo:将当前行row增加到adjMat末尾
        }
        //printAdjMat();调试一下
    }
    void update(queue<int>& my_queue, int rootNo)
    {


        for(int j = 0; j < n; j++)
        {

        }
    }
    void BFS(int startNo = 0)
    {



        queue<int> my_queue;


        while(!my_queue.empty())
        {
            int root;
        }
        //
    }
    void main()
    {
        readAdjMat();
        BFS();
    }
};

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    while(t--)
    {
        Graph g;
        g.main();
    }
    return 0;
}