#include<iostream>
using namespace std;

class BiTNode
{
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
    BiTNode *parent;//父节点
public:
    BiTNode(): lchild(NULL), rchild(NULL), parent(NULL){}
    BiTNode(char data_): data(data_), lchild(NULL), rchild(NULL), parent(NULL){}
    friend class BiTree;
};

class BiTree
{
    BiTNode *rt;
public:
    BiTree(): rt(NULL){}
    void CreateTree(){CreateTree(rt, NULL);}//所有操作中的第一步
    void CreateTree(BiTNode *&t, BiTNode *p);//递归创建二叉树
    void leave(){leave(rt);}
    void leave(BiTNode *t);
    void fa(){fa(rt);}
    void fa(BiTNode *t);
};
void BiTree::CreateTree(BiTNode *&t, BiTNode *p)//t当前节点，p父节点
{
    char c;
    cin >> c;
    if(c == '0')
    {
        t = NULL;
    }
    else
    {
        t = new BiTNode(c);
        t->parent = p;
        CreateTree(t->lchild, t);
        CreateTree(t->rchild, t);
    }
}
void BiTree::leave(BiTNode *t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        if(t->lchild == NULL && t->rchild == NULL)
            cout << t->data << " ";
        leave(t->lchild);
        leave(t->rchild);
    }
}
void BiTree::fa(BiTNode *t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        if(t->lchild == NULL && t->rchild == NULL)
            cout << t->parent->data << " ";
        fa(t->lchild);
        fa(t->rchild);
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        BiTree tree;
        tree.CreateTree();
        tree.leave();
        cout << endl;
        tree.fa();
        cout << endl;
    }
    return 0;
}