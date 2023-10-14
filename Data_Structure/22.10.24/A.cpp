#include<iostream>
using namespace std;

class ListNode
{
public:
    int index;
    ListNode *next;
    ListNode(){next = NULL;}
};

class head
{
public:
    char data;
    ListNode *hd;
    ListNode *p;
    head(){hd = new ListNode; p = hd;}
    head(char data_)
    {
        data = data_; hd = new ListNode; p = hd;
    }
};

class arc
{
public:
    char a;
    char b;
    int indexa;
    int indexb;
    arc(){a = 0; b = 0; indexa = -1; indexb = -1;}
    arc(char a_, char b_)
    {
        a = a_; b = b_; indexa = -1; indexb = -1;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    int n, k;
    while(t--)
    {
        head he[1005];
        arc ar[2005];
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> he[i].data;
        }
        for(int i = 0; i < k; i++)//弧
        {
            cin >> ar[i].a >> ar[i].b;
            for(int j = 0; j < n; j++)//结点
            {
                if(ar[i].a == he[j].data)
                {
                    ar[i].indexa = j;
                }
                if(ar[i].b == he[j].data)
                {
                    ar[i].indexb = j;
                }
            }
        }
        for(int i = 0; i < k; i++)//弧
        {
            ListNode *s = new ListNode;
            s->index = ar[i].indexb;
            he[ar[i].indexa].p->next = s;
            s->next = NULL;
            he[ar[i].indexa].p = s;
        }
        for(int i = 0; i < n; i++)//结点
        {
            cout << i << " " << he[i].data << "-";
            he[i].p = he[i].hd;
            while(1)
            {
                if(he[i].p->next)
                    he[i].p = he[i].p->next;
                else
                {
                    cout << "^" << endl;
                    break;
                }
                cout << he[i].p->index << "-";
            }
        }
    }
    return 0;
}