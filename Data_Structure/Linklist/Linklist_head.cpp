#include<iostream>
using namespace std;

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
    Listnode *head = new Listnode;
    Listnode *p = head;
    int n;//有n个结点
    Linklist(int n_)
    {
        n = n_;
        cout << "请输入数据：" << endl;
        for(int i = 0; i < n; i++)
        {
            Listnode *s = new Listnode;
            cin >> s->data;
            //头插法核心
            s->next = head->next;
            head->next = s;
        }
    }
    int Linklist_out()//输出链表
    {
        p = head;
        while(p->next != NULL)
        {
            cout << p->next->data;
            p = p->next;
        }
        cout << endl;
        return 0;
    }
    ~Linklist()//回收链表
    {
        p = head;
        while(p->next != NULL)
        {
            Listnode *temp = p;
            delete p;
            p = temp->next;
        }
    }
};

int main()
{
    int n_ = 0;
    cout << "请输入链表个数：" << endl;
    cin >> n_;
    Linklist link(n_);
    link.Linklist_out();
    return 0;
}