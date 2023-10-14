#include<iostream>
using namespace std;

class Map
{
    int **matrix;
    int m; 
    int n;
public:
    Map(int m_, int n_)
    {
        m = m_; n = n_;
        matrix = new int*[m+2];//多一圈
        for(int i = 0; i < m+2; i++)
            matrix[i] = new int[n+2];

        for(int i = 0; i < m+2; i++)
            for(int j = 0; j < n+2; j++)
                matrix[i][j] = 0;
        matrix[0][0] = 1;//多的外面一圈第一个是1其他全是0

        for(int i = 1; i < m+1; i++)
            for(int j = 1; j < n+1; j++)
                cin >> matrix[i][j];
    }
    ~Map()
    {
        for(int i = 0; i < m+2; i++)
            delete []matrix[i];
        delete []matrix;
    }
    void painting(int x, int y)//（递归方法）涂色：将外围所有0涂成1
    {
        //往右走y++
        if(y+1 != n+2 && matrix[x][y+1] == 0)//注意这需要先判断越界再判断0否则先判断0会因为越界的情况而崩溃
        {
            matrix[x][y+1] = 1;
            painting(x, y+1);
        }
        //往下走x++
        if(x+1 != m+2 && matrix[x+1][y] == 0)
        {
            matrix[x+1][y] = 1;
            painting(x+1, y);
        }
        //往左走y--
        if(y-1 != -1 && matrix[x][y-1] == 0)
        {
            matrix[x][y-1] = 1;
            painting(x, y-1);
        }
        //往上走x--
        if(x-1 != -1 && matrix[x-1][y] == 0)
        {
            matrix[x-1][y] = 1;
            painting(x-1, y);
        }
    }
    int count()//计数：涂色后数出整个图中0的数量,期中手动添加的外围一圈不用参与计算
    {
        int num = 0;
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(matrix[i][j] == 0) 
                    num++;
            }
        }
        return num;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    int m = 0, n = 0;
    while(t--)
    {
        cin >> m >> n;
        Map map(m, n);
        map.painting(0, 0);
        cout << map.count() << endl;
    }
    return 0;
}