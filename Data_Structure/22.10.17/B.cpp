#include<iostream>
#include<queue>
using namespace std;

class BiTNode
{
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
    BiTNode *parent;
public:
    BiTNode()
    {
        lchild = NULL; rchild = NULL; parent = NULL;
    }
    BiTNode(char data_)
    {
        data = data_; BiTNode();
    }
    friend class BiTree;
};
class BiTree
{
    BiTNode *rt;
public:
    BiTree(){rt = NULL;}
    ~BiTree(){delete rt;}
    void CreatTree();
    void CreatTree(BiTNode *&t, BiTNode *p);
    void LevelOrder();
    void LevelOrder(BiTNode *t);
};
void BiTree::CreatTree()
{
    CreatTree(rt, NULL);
}
void BiTree::CreatTree(BiTNode *&t, BiTNode *p)
{
    char c;
    cin >> c;
    if(c == '0')
        t = NULL;
    else
    {
        t = new BiTNode(c);
        t->parent = p;
        CreatTree(t->lchild, t);
        CreatTree(t->rchild, t);
    }
}
void BiTree::LevelOrder()
{
    LevelOrder(rt);
}
void BiTree::LevelOrder(BiTNode *t)
{
    queue<BiTNode*> tq;
    BiTNode *p = t;
    if(p != NULL)
    {
        tq.push(p);
    }
    while(!tq.empty())
    {
        p = tq.front();
        tq.pop();
        cout << p->data;
        if(p->lchild != NULL)
            tq.push(p->lchild);
        if(p->rchild != NULL)
            tq.push(p->rchild);
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {  
        BiTree tree;
        tree.CreatTree();
        tree.LevelOrder();
        cout << endl;
    }
    return 0;
}