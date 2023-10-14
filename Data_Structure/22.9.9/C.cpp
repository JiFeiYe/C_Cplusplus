#include<iostream>
using namespace std;

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
    Listnode *head = NULL;
    Listnode *p = NULL;
    int n;
    Linklist()
    {
        head = new Listnode;
        p = head;
        n = 0;
    }
    Linklist(int n_)
    {
        head = new Listnode;
        p = head;
        n = n_;
        for(int i = 0; i < n; i++)
        {
            Listnode *s = new Listnode;
            cin >> s->data;
            p->next = s;
            p = s;
        }
    }
    ~Linklist()//有误
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
    void add(Listnode *s)
    {
        p = head;
        for(int i = 0; i < n; i++)
        {
            p = p->next;
        }
        p->next = s;
        p = s;
        n++;
    }
};

int Combine(Linklist L1, Linklist L2)
{
    Linklist *L3 = new Linklist;
    L1.p = L1.head->next; L2.p = L2.head->next;
    while(L1.p && L2.p)
    {
        if(L1.p->data < L2.p->data)
        {
            L3->add(L1.p);
            L1.p = L1.p->next;
        }
        else
        {
            L3->add(L2.p);
            L2.p = L2.p->next;
        }
    }
    if(L1.p)
    {
        L3->add(L1.p);
    }
    else
    {
        L3->add(L2.p);
    }
    L3->display();
    return 0;
}

int main()
{
    int n = 0, m = 0;
    cin >> n;
    Linklist L1(n);
    cin >> m;
    Linklist L2(m);
    Combine(L1, L2);
    return 0;
}