#include<iostream>
using namespace std;
#define ok 0;
#define error -1;

class Listnode
{
public:
    int data;
    Listnode *next;
    Listnode()
    {
        next = NULL;
    }
};

class Linklist
{
public:
    Listnode *head = new Listnode;
    Listnode *p = head;
    int n;
    Linklist(int n_)//创建链表
    {
        n = n_;
        for(int i = 0; i < n; i++)
        {
            Listnode *s = new Listnode;
            cin >> s->data;
            p->next = s;
            p = s;
        }
    }
    ~Linklist()
    {
        p = head;
        Listnode *temp;
        while(p)
        {
            temp = p;
            p = p->next;
            delete temp;
        }
        n = 0;
        head = NULL;
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
    int swap(int pa, int pb)//交换函数
    {
        if(pa < 1 || pb < 1 || pa > n || pb > n)
            return error;
        Listnode *p_ = head;
        p = head;
        while(--pa)
        {
            p = p->next;
        }
        while(--pb)
        {
            p_ = p_->next;
        }
        if(abs(pa-pb) == 1)
        {
            p->next = p_->next;
            p_->next = p_->next->next;
            p->next->next = p_;
            this->display();
            return ok;
        }
        Listnode *temp = p->next;
        Listnode *temp_ = p_->next->next;
        p->next = p_->next;
        p_->next->next = temp->next;
        p_->next = temp;
        temp->next = temp_;
        this->display();
        return ok;
    }
};

int main()
{
    int n_ = 0;
    cin >> n_;
    Linklist ll(n_);
    ll.display();
    int pa = 0, pb = 0;
    cin >> pa >> pb;
    if(ll.swap(pa, pb))
        cout << "error" << endl;
    cin >> pa >> pb;
    if(ll.swap(pa, pb))
        cout << "error" << endl;
    return 0;
}