#include<iostream>
using namespace std;
const int MaxN = 1005;
const int MaxM = 20;
typedef struct
{
    int a;
    int index;
}pa;
pa List[MaxM];
int arr[MaxN];

int main()
{
    int n = 0;
    cin >> n;//主表有n个数据
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k = 0;
    cin >> k;//主表划分成k个块，索引表长度也为k
    int temp = 0, temp_ = 0;
    cin >> temp;
    List[0].a = temp; List[0].index = 0;
    for(int i = 1; i < k; i++)//除去第一次剩k-1次
    {
        cin >> temp_;
        for(int j = List[i-1].index; j < n; j++)
        {
            if(temp < arr[j])
            {
                List[i].index = j;
                List[i].a = temp_;
                break;
            }
        }
        if(i == k-1)
        {
            List[i+1].index = n-1;
        }
        temp = temp_;
    }
    int t = 0;
    cin >> t;//有t个要查找的数值
    int a = 0, index = -1, count = 0;
    while(t--)
    {
        cin >> a;
        index = -1;
        count = 0;
        for(int i = 0; i < k; i++)
        {
            count++;
            if(a <= List[i].a)
            {
                for(int j = List[i].index; j <= List[i+1].index; j++)
                {
                    count++;
                    if(a == arr[j])
                    {
                        index = j;
                        goto there;
                    }
                }
            }
        }
there:
        if(index != -1)
            cout << index+1 << "-" << count << endl;
        else
            cout << "error" << endl;
    }
    return 0;
}