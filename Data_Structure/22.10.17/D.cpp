#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue <int> que;
stack <int>st;

class HuffmanNode
{
    int weight;
    bool flag;
    HuffmanNode *lchild;
    HuffmanNode *rchild;
    HuffmanNode *parent;
public:
    HuffmanNode()
    {
        lchild = NULL; rchild = NULL; parent = NULL; flag = 0; weight = 0;
    }
    HuffmanNode(int weight_)
    {
        weight = weight_; flag = 1; lchild = NULL; rchild = NULL; parent = NULL;
    }
    int getweight()
    {
        return weight;
    }
    friend class HuffmanTree;
};
struct cmp
{
    bool operator() (HuffmanNode *&a, HuffmanNode *&b)
    {
        return a->getweight() > b->getweight();
    }
};

priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp> pque;

class HuffmanTree
{
    HuffmanNode *rt;
public:
    HuffmanTree(){rt = NULL;}
    ~HuffmanTree(){delete rt;}
    void CreatTree();
    void FindParent();//找父亲
    void FindParent(HuffmanNode *t);
    void answer();//题目要求
    void answer(HuffmanNode *t);
};
void HuffmanTree::CreatTree()
{
    do
    {
        HuffmanNode *first = pque.top();
        pque.pop();
        if(pque.empty())
        {
            rt = first;
            return;
        }
        HuffmanNode *rooot = new HuffmanNode;
        rooot->lchild = first;
        rooot->rchild = pque.top();
        rooot->weight = rooot->lchild->weight + rooot->rchild->weight;
        pque.pop();
        pque.push(rooot);
    } while (!pque.empty());
}
void HuffmanTree::FindParent()
{
    FindParent(rt);
}
void HuffmanTree::FindParent(HuffmanNode *t)
{
    if(t->lchild != NULL)
    {
        t->lchild->parent = t;
        FindParent(t->lchild);
    }
    if(t->rchild != NULL)
    {
        t->rchild->parent = t;
        FindParent(t->rchild);
    }
}
void HuffmanTree::answer()
{
    answer(rt);
}
void HuffmanTree::answer(HuffmanNode *t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        if(t->weight == que.front())
        {
            HuffmanNode *temp = t;
            cout << temp->weight << "-";
            while(temp != rt)
            {
                if(temp == temp->parent->lchild)
                {
                    st.push(0);
                    temp = temp->parent;
                }
                else if(temp == temp->parent->rchild)
                {
                    st.push(1);
                    temp = temp->parent;
                }
            }
            while(!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << endl;
        }
        answer(t->lchild);
        answer(t->rchild);
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        HuffmanTree htree;
        int n = 0;
        cin >> n;
        int weight;
        while(n--)
        {
            cin >> weight;
            HuffmanNode *t = new HuffmanNode(weight);
            pque.push(t);
            que.push(weight);
        }
        htree.CreatTree();
        htree.FindParent();
        while(!que.empty())
        {
            htree.answer();
            int temp = que.front();
            que.pop();
            if(que.front() == temp)
                que.pop();
        }
    }
    return 0;
}