//先、后序创建二叉树
#include<iostream>
using namespace std;

string str;

class BiTNode
{
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
    BiTNode *parent;
public:
    BiTNode(){lchild = NULL; rchild = NULL; parent = NULL;}
    BiTNode(char data_)
    {
        data = data_; BiTNode();
    }
    friend class BiTree;
};
class BiTree
{
    BiTNode *rt;//根节点
public:
    BiTree(){rt = NULL;}
    ~BiTree(){delete rt;}
    void CreatTree();
    void CreatTree(BiTNode *&t, BiTNode *p); //先序创建二叉树（填入'#'）
    void CreatTree_();
    void CreatTree_(BiTNode *&t, BiTNode *p); //后序创建二叉树
    void Postorder_Traversal();
    void Postorder_Traversal(BiTNode *t); //特殊的
    void Inorder_Traversal();
    void Inorder_Traversal(BiTNode *t); //普通的
    void Preorder_Traversal();
    void Preorder_Traversal(BiTNode *t); //普通的
};
void BiTree::CreatTree()
{
    CreatTree(rt, NULL);
}
void BiTree::CreatTree(BiTNode *&t, BiTNode *p)
{
    char c;
    cin >> c;
    if(c == '#')
    {
        t = new BiTNode(c);
        t->parent = p;
        t->lchild = NULL;
        t->rchild = NULL;
    }
    else
    {
        t = new BiTNode(c);
        t->parent = p;
        CreatTree(t->lchild, t);
        CreatTree(t->rchild, t);
    }
}
void BiTree::CreatTree_()
{
    CreatTree_(rt, NULL);
}
void BiTree::CreatTree_(BiTNode *&t, BiTNode *p)
{
    static int count = str.size();
    char c = str[--count];
    if(c == '#')
        t = NULL;
    else
    {
        t = new BiTNode(c);
        t->parent = p;
        CreatTree_(t->rchild, t);
        CreatTree_(t->lchild, t);
    }
}
void BiTree::Postorder_Traversal()
{
    Postorder_Traversal(rt);
}
void BiTree::Postorder_Traversal(BiTNode *t)
{
    if(t->lchild != NULL)
        Postorder_Traversal(t->lchild);
    if(t->rchild != NULL)
        Postorder_Traversal(t->rchild);
    str += t->data;
}
void BiTree::Inorder_Traversal()
{
    Inorder_Traversal(rt);
}
void BiTree::Inorder_Traversal(BiTNode *t)
{
    if(t->lchild != NULL)
        Inorder_Traversal(t->lchild);
    if(t->data != '#')
        cout << t->data;
    if(t->rchild != NULL)
        Inorder_Traversal(t->rchild);
}
void BiTree::Preorder_Traversal()
{
    Preorder_Traversal(rt);
}
void BiTree::Preorder_Traversal(BiTNode *t)
{
    if(t->data != '#')
        cout << t->data;
    if(t->lchild != NULL)
        Preorder_Traversal(t->lchild);
    if(t->rchild != NULL)
        Preorder_Traversal(t->rchild);
}

int main()
{
    BiTree tree1, tree2;
    tree1.CreatTree();
    tree1.Inorder_Traversal();
    cout << endl;
    tree1.Preorder_Traversal();
    cout << endl;

    tree1.Postorder_Traversal();

    tree2.CreatTree_();
    tree2.Inorder_Traversal();
    cout << endl;
    tree2.Preorder_Traversal();
    return 0;
}
/*
421##3##65##7##
*/