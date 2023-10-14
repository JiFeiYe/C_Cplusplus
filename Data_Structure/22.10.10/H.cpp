#include<iostream>
using namespace std;

int count = 0;

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
    void countleave(){countleave(rt);}
    void countleave(BiTNode *t);
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
void BiTree::countleave(BiTNode *t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        if(t->lchild == NULL && t->rchild == NULL)
            count++;
        countleave(t->lchild);
        countleave(t->rchild);
    }
}


int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        count = 0;
        BiTree tree;
        tree.CreateTree();
        tree.countleave();
        cout << count << endl;
    }
    return 0;
}