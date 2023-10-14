#include<iostream>
#include<queue>
using namespace std;

int compare(int num, int **qu, int *number, int t)
{
    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < number[i]; j++)
        {
            if(num == qu[i][j])
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int t = 0;
    cin >> t;
    int **qu = new int *[t];//t组数据
    int n = 0;//每一组里面各自有n个
    int *number = new int [t];//t个下标、数组个数
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        qu[i] = new int[n];
        number[i] = n;
        for(int j = 0; j < n; j++)
        {
            cin >> qu[i][j];
        }
    }
    queue <int> *que = new queue <int> [t];
    string str = " ";
    int num = 0;
    int count = 0;
    int count_ = 0;
    int flag = 0;
    int flag_ = 0;
    bool *bol = new bool [t];
    while(1)
    {
        cin >> str;
        if(str == "ENQUEUE")
        {
            cin >> num;
            for(int i = 0; i < count; i++)
            {
                if(compare(num, qu, number, t) == compare(que[i].front(), qu, number, t))
                {
                    que[i].push(num);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                que[count].push(num);
                bol[count] = true;
                count++;
            }
            flag = 0;
        }
        else if(str == "DEQUEUE")
        {
            if(flag_ == 0)
            {
                cout << que[0].front();
                que[0].pop();
                if(que[0].empty())
                {
                    bol[0] = false;
                }
                flag_ = 1;
            }
            else
            {
                if(bol[count_] == true)
                {
                    cout << " " << que[count_].front();
                    que[count_].pop();
                }
                
                if(que[count_].empty())
                {
                    bol[count_] = false;
                    count_++;
                }
            }
        }
        else if(str == "STOP")
        {
            cout << endl;
            break;
        }
    }
    for(int i = 0; i < t; i++)
    {
        delete []qu[i];
    }
    delete []qu;
    delete []number;
    delete []que;
    delete []bol;
    return 0;
}