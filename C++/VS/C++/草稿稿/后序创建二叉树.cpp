#include<iostream>
using namespace std;

string str;

class BiTNode
{
    char data;
    BiTNode* lchild;
    BiTNode* rchild;
    BiTNode* parent;
public:
    BiTNode() { lchild = NULL; rchild = NULL; parent = NULL; }
    BiTNode(char data_)
    {
        data = data_; BiTNode();
    }
    friend class BiTree;
};
class BiTree
{
    BiTNode* rt;//¸ù½Úµã
public:
    BiTree() { rt = NULL; }
    ~BiTree() { delete rt; }
    void CreatTree();
    void CreatTree(BiTNode*& t, BiTNode* p);
    void CreatTree_();
    void CreatTree_(BiTNode*& t, BiTNode* p);
    void Postorder_Traversal();
    void Postorder_Traversal(BiTNode* t);
    void Inorder_Traversal();
    void Inorder_Traversal(BiTNode* t);
};
void BiTree::CreatTree()
{
    CreatTree(rt, NULL);
}
void BiTree::CreatTree(BiTNode*& t, BiTNode* p)
{
    char c;
    cin >> c;
    if (c == '#')
        t = NULL;
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
void BiTree::CreatTree_(BiTNode*& t, BiTNode* p)
{
    static int count = str.size();
    char c = str[--count];
    if (c == '#')
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
void BiTree::Postorder_Traversal(BiTNode* t)
{
    if (t->lchild != NULL)
        Postorder_Traversal(t->lchild);
    if (t->rchild != NULL)
        Postorder_Traversal(t->rchild);
    str += t->data;
}
void BiTree::Inorder_Traversal()
{
    Inorder_Traversal(rt);
}
void BiTree::Inorder_Traversal(BiTNode* t)
{
    if (t->lchild != NULL)
        Inorder_Traversal(t->lchild);
    cout << t->data;
    if (t->rchild != NULL)
        Inorder_Traversal(t->rchild);
}

int main()
{
    BiTree tree1, tree2;
    tree1.CreatTree();
    tree1.Postorder_Traversal();
    tree2.CreatTree_();
    tree2.Inorder_Traversal();
    return 0;
}