#include<iostream>
using namespace std;
#define ok 0
#define error -1

class Listnode
{
public:
    int data;
    Listnode *next;
    Listnode(){next = NULL;}
};

class Linklist
{
public:
    Listnode *head = NULL;
    Listnode *p = NULL;
    int n;
    Linklist(int n_)//创建链表
    {
        head = new Listnode;
        p = head;
        n = n_;
        for(int i = 0; i < n; i++)//尾插法
        {
            Listnode *s = new Listnode;
            cin >> s->data;
            p->next = s;
            s->next = NULL;
            p = s;
        }
    }
    ~Linklist()
    {
        p = head;
        Listnode *temp;
        while(p != NULL)
        {
            temp = p;
            p = p->next;
            delete temp;
        }
        n = 0;
        head = NULL;
    }
    int Empty()
    {
        return head->next == NULL;
    }
    Listnode *LL_index(int i)//返回第i个结点的指针
    {
        p = head;
        while(i--)
        {
            p = p->next;
        }
        return p;
    }
    int LL_get(int i)//获得第i个元素的数据
    {
        if(Empty() || i > n || i < 1)
            return error;
        p = head;
        while(i--)
        {
            p = p->next;
        }
        cout << p->data << endl;
        return ok;
    }
    int LL_insert(int i, int item)//把数值item插入到第i个位置
    {
        if(Empty() || i > n+1 || i < 1)
            return error;
        p = head;
        while(--i)
        {
            p = p->next;
        }
        Listnode *s = new Listnode;
        s->data = item;
        s->next = p->next;
        p->next = s;
        n++;
        this->display();
        return ok;
    }
    int LL_del(int i)//删除元素
    {
        if(Empty() || i > n || i < 1)
            return error;
        p = head;
        while(--i)
        {
            p = p->next;
        }
        Listnode *temp = p->next;
        p->next = p->next->next;
        delete temp;
        n--;
        this->display();
        return ok;
    }
    void display()
    {
        p = head->next;
        while(p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    int n_ = 0;
    cin >> n_;
    Linklist ll(n_);
    ll.display();
    int i = 0, item = 0;
    cin >> i >> item;
    if(ll.LL_insert(i, item))//插入
        cout << "error" << endl;
    cin >> i >> item;
    if(ll.LL_insert(i, item))//插入
        cout << "error" << endl;
    cin >> i;
    if(ll.LL_del(i))//删除
        cout << "error" << endl;
    cin >> i;
    if(ll.LL_del(i))//删除
        cout << "error" << endl;
    cin >> i;
    if(ll.LL_get(i))//查找
        cout << "error" << endl;
    cin >> i;
    if(ll.LL_get(i))//查找
        cout << "error" << endl;
    return 0;
}