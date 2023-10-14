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
    void Delete(int d);
    void Delete(BsTNode* &T, int d);
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
void BsTree::Delete(int d)
{
    Delete(rt, d);
}
void BsTree::Delete(BsTNode* &T, int d)
{
    //首先找到要被删除的节点
    BsTNode *P = T;
    while(P != NULL && d != P->data)
    {
        if(d > P->data)
        {
            P = P->rchild;
        }
        else
        {
            P = P->lchild;
        }
    }
    if(P == NULL)
        return;
    else
    {
        //当前节点是叶子结点时，直接删除
        if(P->lchild == NULL && P->rchild == NULL)
        {
            if(P->data > P->parent->data)
                P->parent->rchild = NULL;
            else
                P->parent->lchild = NULL;
        }
        //当前节点仅有一个左孩子或者一个右孩子时，让孩子替代他的位置
        if((P->lchild != NULL && P->rchild == NULL) || (P->rchild != NULL && P->lchild == NULL))
        {
            if(P->data > P->parent->data)
                if(P->lchild != NULL)
                    P->parent->rchild = P->lchild;
                else
                    P->parent->rchild = P->rchild;
            else
                if(P->lchild != NULL)
                    P->parent->lchild = P->lchild;
                else
                    P->parent->lchild = P->rchild;
        }
        //当左右孩子都有时，寻找左子树中序遍历的上一个节点或下一个节点替代其位置。
        if(P->lchild != NULL && P->rchild != NULL)
        {
            BsTNode* Q = P->lchild;
            while(Q->rchild)
            {
                Q = Q->rchild;
            }
            P->data = Q->data;
            if(P != Q->parent)
                Q->parent->rchild = Q->lchild;
            else
                Q->parent->lchild = Q->lchild;
            delete(Q);
        }
    }
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
        int m = 0;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int d = 0;
            cin >> d;
            tree.Delete(d);
            tree.Inorder_Traversal();
        }
    }
    return 0;
}