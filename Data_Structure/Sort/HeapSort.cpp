/*
【从堆的定义到优先队列、堆排序】 10分钟看懂必考的数据结构——堆】
https://www.bilibili.com/video/BV1AF411G7cA/?share_source=copy_web&vd_source=c063d9ba1de185b173c86f73e8e05f31
*/
#include<iostream>
using namespace std;

int a[1005];
void Swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
int HeapAdjust(int flag, int i)
{
    if(flag == 0)
    {
        int temp = i;
        while(a[temp] >= a[2*temp+1] || a[temp] >= a[2*temp+2])
        {
            if(a[2*temp+1] <= a[2*temp+2])
            {
                Swap(a[temp], a[2*temp+1]);
                temp = 2*temp+1;
            }
            else
            {
                Swap(a[temp], a[2*temp+2]);
                temp = 2*temp+2;
            }
        }
    }
    else if(flag == 1)
    {
        int temp = 0;
        while(a[temp] >= a[2*temp+1] || a[temp] >= a[2*temp+2])
        {
            if(2*temp+1 < i && a[2*temp+1] <= a[2*temp+2])
            {
                Swap(a[temp], a[2*temp+1]);
                temp = 2*temp+1;
            }
            else if(2*temp+2 < i && a[2*temp+1] > a[2*temp+2])
            {
                Swap(a[temp], a[2*temp+2]);
                temp = 2*temp+2;
            }
            else if(2*temp+1 == i-1 && a[temp] >= a[2*temp+1])
            {
                Swap(a[temp], a[2*temp+1]);
                temp = 2*temp+1;
            }
            else
                break;
        }
    }
    else 
        return 1;
    return 0;
}
void Print(int n);
void HeapSort(int n)//小顶堆
{
    for(int i = (n-2)/2; i >= 0; i--)//i从最后一个父节点遍历到根节点
        HeapAdjust(0, i);
    Print(n);
    for(int i = n-1; i > 0; i--)//i从最后一个叶节点到根节点的左子节点
    {
        Swap(a[0], a[i]);
        HeapAdjust(1, i);
    }
    Print(n);
}
void Print(int n)
{
    cout << a[0];
    for(int i = 1; i < n ; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 1005; i++)
            a[i] =0x3f3f3f;
        int n = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        HeapSort(n);
    }
    return 0;
}
/*
1
8 34 23 677 2 1 453 3 7
*/