#include<iostream>
using namespace std;

class BsTNode
{
    int data;
    BsTNode *lchild;
    BsTNode *rchild;
    BsTNode*parent;
public:
    BsTNode()
    {
        lchild = NULL; rchild = NULL; parent = NULL;
    }
    BsTNode(int data_)
    {
        data = data_; lchild = NULL; rchild = NULL; parent = NULL;
    }
    friend class BsTree;
};
class BsTree
{
    BsTNode *rt;
public:
    BsTree(){rt = NULL;}
    ~BsTree(){delete rt;}
    void CreatTree(int d_);//创建二叉排序树（每调用一次创建一个节点）
    void CreatTree(BsTNode *&t, BsTNode *p, int d_);
    void InsertTree(int d_);//插入操作
    void InsertTree(BsTNode *&t, int d_);
    int SeekTree(int seek);
    int SeekTree(int seek, BsTNode *rooot);
    void Inorder_Traversal();//中序遍历（递归算法）
    void Inorder_Traversal(BsTNode *t);
};
void BsTree::CreatTree(int d_)
{
    CreatTree(rt, NULL, d_);
}
void BsTree::CreatTree(BsTNode *&t, BsTNode *p, int d_)
{
    if(t == NULL)
    {
        t = new BsTNode(d_);
        t->parent = p;
        t->lchild = NULL;
        t->rchild = NULL;
    }
    else if(d_ > t->data)
        CreatTree(t->rchild, t, d_);
    else if(d_ < t->data)
        CreatTree(t->lchild, t, d_);
}
void BsTree::InsertTree(int d_)
{
    InsertTree(rt, d_);
}
void BsTree::InsertTree(BsTNode *&t, int d_)
{
    BsTNode *temp = t;
    BsTNode *pre = NULL;
    while(temp != NULL && d_ != temp->data)//寻找有无相同数
    {
        if(d_ > temp->data)
        {
            pre = temp;
            temp = temp->rchild;
        }
        else if(d_ < temp->data)
        {
            pre = temp;
            temp = temp->lchild;
        }
    }
    if(!temp)
    {
        BsTNode *p;
        p = new BsTNode;
        p->data = d_;
        if(p->data > pre->data)
        {
            pre->rchild = p;
            p->parent = pre;
        }
        else if(p->data < pre->data)
        {
            pre->lchild = p;
            p->parent = pre;
        }
    }
}
int num;
int BsTree::SeekTree(int seek)
{
    return SeekTree(seek, rt);
}
int BsTree::SeekTree(int seek, BsTNode *rooot)
{
    BsTNode *p = rooot;
    if(p == NULL)
        return -1;
    if(seek == p->data)
        return num;
    else if(seek < p->data)
    {
        num++;
        return SeekTree(seek, p->lchild);
    }
    else if(seek > p->data)
    {
        num++;
        return SeekTree(seek, p->rchild);
    }
    return -1;
}
void BsTree::Inorder_Traversal()
{
    Inorder_Traversal(rt); cout << endl;
}
void BsTree::Inorder_Traversal(BsTNode *t)
{
    if(t->lchild != NULL)
        Inorder_Traversal(t->lchild);
    cout << t->data << " ";
    if(t->rchild != NULL)
        Inorder_Traversal(t->rchild);
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        BsTree tree;
        int n = 0;
        cin >> n;   
        for(int i = 0; i < n; i++)
        {
            int d = 0;
            cin >> d;
            tree.CreatTree(d);
        }
        tree.Inorder_Traversal();
        int sn = 0;
        cin >> sn;
        int seek = 0;
        for(int i = 0; i < sn; i++)
        {
            num = 1;
            cin >> seek;
            cout << tree.SeekTree(seek) << endl;
        }
    }
    return 0;
}
