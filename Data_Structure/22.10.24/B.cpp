#include<iostream>
using namespace std;

class arc
{
public:
    string a;
    string b;
    int indexa;
    int indexb;
    arc(){a = ""; b = ""; indexa = -1; indexb = -1;}
    arc(string a_, string b_)
    {
        a = a_; b = b_; indexa = -1; indexb = -1;
    }
};

int main()
{
    int T = 0;
    cin >> T;
    char type = ' ';//D有向图，U无向图
    int vnum = 0;
    int arcnum = 0;
    while(T--)
    {
        cin >> type >> vnum;
        string strv[1005];
        for(int i = 0; i < vnum; i++)//结点
        {
            cin >> strv[i];
        }
        cin >> arcnum;
        arc ar[2005];
        for(int i = 0; i < arcnum; i++)//弧
        {
            cin >> ar[i].a >> ar[i].b;
            for(int j = 0; j < vnum; j++)//结点
            {
                if(ar[i].a == strv[j])
                    ar[i].indexa = j;
                if(ar[i].b == strv[j])
                    ar[i].indexb = j;
            }
        }
        int matrix[505][505] = {0};//邻接矩阵
        for(int i = 0; i < arcnum; i++)
        {
            matrix[ar[i].indexa][ar[i].indexb] = 1;
        }
        if(type == 'U')
        {
            for(int i = 0; i < vnum; i++)
            {
                for(int j = 0; j < vnum; j++)
                {
                    if(matrix[i][j] == 1)
                        matrix[j][i] = matrix[i][j];
                    else if(matrix[j][i] == 1)
                        matrix[i][j] = matrix[j][i]; 
                }
            }
        }
        for(int i = 0; i < vnum; i++)
        {
            cout << matrix[i][0];
            for(int j = 1; j < vnum; j++)
            {
                cout << " " << matrix[i][j];
            }
            cout << endl;
        }
        int out = 0, in = 0;
        for(int k = 0; k < vnum; k++)
        {
            out = 0; in = 0;
            if(type == 'D')
            {
                //cout << strv[k] << ":";
                for(int i = 0; i < vnum; i++)//结点
                {
                    out += matrix[k][i];
                }
                for(int i = 0; i < vnum; i++)
                {
                    in += matrix[i][k];
                }
                if(in + out != 0)
                    cout << strv[k] << ":";
                else
                {
                    cout << strv[k] << endl;
                    continue;
                }
                cout << " " << out << " " << in << " " << out+in << endl;
            }
            else if(type == 'U')
            {
                //cout << strv[k] << ":";
                for(int i = 0; i < vnum; i++)//用out代指无向图结点的度
                {
                    out += matrix[k][i];
                }
                if(out != 0)
                    cout << strv[k] << ":";
                else
                {
                    cout << strv[k] << endl;
                    continue;
                }
                cout << " " << out << endl;
            }
        }
    }
    return 0;
}