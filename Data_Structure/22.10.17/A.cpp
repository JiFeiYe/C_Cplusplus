#include<iostream>
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
    void Preorder_Traversal();
    void Inorder_Traversal();
    void Postorder_Traversal();
    void Preorder_Traversal(BiTNode *t);
    void Inorder_Traversal(BiTNode *t);
    void Postorder_Traversal(BiTNode *t);
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
        t = NULL;
    else
    {
        t = new BiTNode(c);
        t->parent = p;
        CreatTree(t->lchild, t);
        CreatTree(t->rchild, t);
    }
}
void BiTree::Preorder_Traversal(){Preorder_Traversal(rt); cout << endl;}
void BiTree::Inorder_Traversal(){Inorder_Traversal(rt); cout << endl;}
void BiTree::Postorder_Traversal(){Postorder_Traversal(rt); cout << endl;}
void BiTree::Preorder_Traversal(BiTNode *t)
{
    cout << t->data;
    if(t->lchild != NULL)
        Preorder_Traversal(t->lchild);
    if(t->rchild != NULL)
        Preorder_Traversal(t->rchild);
}
void BiTree::Inorder_Traversal(BiTNode *t)
{
    if(t->lchild != NULL)
        Inorder_Traversal(t->lchild);
    cout << t->data;
    if(t->rchild != NULL)
        Inorder_Traversal(t->rchild);
}
void BiTree::Postorder_Traversal(BiTNode *t)
{
    if(t->lchild != NULL)
        Postorder_Traversal(t->lchild);
    if(t->rchild != NULL)
        Postorder_Traversal(t->rchild);
    cout << t->data;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {  
        BiTree tree;
        tree.CreatTree();
        tree.Preorder_Traversal();
        tree.Inorder_Traversal();
        tree.Postorder_Traversal();
    }
    return 0;
}