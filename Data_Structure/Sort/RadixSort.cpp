#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int a[1005];
queue <int> q[10];

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 10; i++)//清空 q
            while(!q[i].empty())
                q[i].pop();
        int n = 0;
        cin >> n;
        int max = -10000;//获取最大数
        int min = 10000;//用于控制负数情况
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(max < a[i])
                max = a[i];
            if(min > a[i])
                min = a[i];
        }
        //有负数情况下的处理
        if(min < 0)
            for(int i = 0; i < n; i++)
                a[i] -= min;
        //基数排序
        int times = (int)(log10(max))+1;
        for(int i = 10; times--; i*=10)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = (a[j] % i) / (i / 10);
                q[temp].push(a[j]);
            }
            int index = 0;
            for(int j = 0; j < 10; j++)
            {
                while(!q[j].empty())
                {
                    a[index++] = q[j].front();
                    q[j].pop();
                }
            }
        }
        //有负数情况下的处理的后续
        if(min < 0)
            for(int i = 0; i < n; i++)
                a[i] += min;
        //输出
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
/*
2
10 278 109 63 930 589 184 505 269 8 83
6 57 0 93 19 18 99
*/