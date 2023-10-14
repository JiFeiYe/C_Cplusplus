#include<iostream>
#define Maxsize 6

struct Node
{
    int data;
    int cur;
};

class Linklist
{
public:
    Node arr[Maxsize];
    Linklist(){}
    // Linklist(Node *arr_)
    // {
    //     for(int i = 0; i < Maxsize; i++)
    //     {
    //         arr[i] = arr_[i];
    //     }
    // }
    void Init()//初始化创建备用链表
    {
        for(int i = 0; i < Maxsize; i++)
        {
            arr[i].cur = i + 1;
            arr[i].data = 0;
        }
        arr[Maxsize].cur = 0;
        return;
    }
    int mallocArr()//为数据存入链表模拟分配空间，调整备用链表内容
    {
        int i = arr[0].cur;
        if(arr[0].cur)
        {
            arr[0].cur = arr[i].cur;
        }
        return i;
    }
    void add()//往链表添加元素
    {
        int n = 0;
        printf("请输入将添加的数据成员数量:\n");
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            printf("请输入第%d个成员:\n", i);
            scanf("%d", &arr[i].data);
            arr[i].cur = i + 1;
        }
        arr[0].cur = n+1;
        arr[n].cur = 0;
        
    }
    void insertArr(int cur, int num)
    {

    }
};
