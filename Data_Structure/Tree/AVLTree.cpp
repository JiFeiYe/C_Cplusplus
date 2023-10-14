/*AVL树是在二叉排序树的基础上加上平衡操作得到的二叉平衡树*/
/*平衡操作分LL、RR、LR、RL*/
#include<iostream>
using namespace std;

class AVLNode
{
    int data;
    int height;
    AVLNode *lchild;
    AVLNode *rchild;
    AVLNode *parent;
public:
    AVLNode()
    {
        lchild = NULL; rchild = NULL; parent = NULL;
    }
    AVLNode(int data_)
    {
        data = data_; height = 0; lchild = NULL; rchild = NULL; parent = NULL;
    }
    void setheight(int height_)//节点相对高度
    {
        height = height_;
    }
    friend class AVLTree;
};
class AVLTree
{
public:
    AVLNode *rt;
    AVLTree(){rt = NULL;}
    ~AVLTree(){delete rt;}
    AVLNode* InsertTree(AVLNode *t, int d_);//插入操作（兼容创建）
    void Delete(int d);//删除操作
    void Delete(AVLNode* &T, int d);
    int CalcHeight(AVLNode *T);//计算相对高度
    int CalcBF(AVLNode *T);//Calculate
    AVLNode* LL(AVLNode *y);
    AVLNode* RR(AVLNode *y);
    AVLNode* LR(AVLNode *y);
    AVLNode* RL(AVLNode *y);
    void Inorder_Traversal();//中序遍历（递归算法）
    void Inorder_Traversal(AVLNode *t);
};
AVLNode* AVLTree::InsertTree(AVLNode *t, int d_)
{
    if(!t)
    {
        AVLNode* s = new AVLNode;
        s->data = d_;
        t = s;
    }
    else if(d_ < t->data)
        t->lchild = InsertTree(t->lchild, d_);
    else if(d_ > t->data)
        t->rchild = InsertTree(t->rchild, d_);
    else
        return t;
    t->height = CalcHeight(t);
    int bf = CalcBF(t);
    //LL
    if(bf > 1 && d_ < t->lchild->data)
        return LL(t);
    //RR
    else if(bf < -1 && d_ > t->rchild->data)
        return RR(t);
    //LR（左孩子的右子树）
    else if(bf > 1 && d_ > t->lchild->data)
    {
        t->lchild = RR(t->lchild);
        return LL(t);
    }
    //RL（右孩子的左子树）
    else if(bf < -1 && d_ < t->rchild->data)
    {
        t->rchild = LL(t->rchild);
        return RR(t);
    }
    return t;
}
void AVLTree::Delete(int d)
{
    Delete(rt, d);
}
void AVLTree::Delete(AVLNode* &T, int d)//unfinsh
{
    //首先找到要被删除的节点
    AVLNode *P = T;
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
            AVLNode* Q = P->lchild;
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
int AVLTree::CalcHeight(AVLNode *T)
{
    if(T->lchild == NULL && T->rchild == NULL)
        return 1;
    else if(T->lchild == NULL)
        return T->rchild->height + 1;
    else if(T->rchild == NULL)
        return T->lchild->height + 1;
    else
        return T->lchild->height > T->rchild->height ? T->lchild->height + 1 : T->rchild->height + 1;
}
int AVLTree::CalcBF(AVLNode *T)
{
    if(T == NULL || (T->lchild == NULL && T->rchild == NULL))
        return 0;
    else if(T->lchild == NULL)
        return -T->rchild->height;
    else if(T->rchild == NULL)
        return T->lchild->height;
    else
        return T->lchild->height - T->rchild->height;
}
AVLNode* AVLTree::LL(AVLNode *y)
{
    AVLNode* x = y->lchild;
    y->lchild = x->rchild;
    x->rchild = y;
    //y
    if(y->rchild == NULL && y->lchild != NULL)
        y->height = y->lchild->height + 1;
    else if(y->rchild != NULL && y->lchild == NULL)
        y->height = y->rchild->height + 1;
    else if(y->rchild == NULL && y->lchild == NULL)
        y->height = 1;
    else
    {
        y->height = y->lchild->height > y->rchild->height ? y->lchild->height + 1 : y->rchild->height + 1;
    }
    //x
    if(x->rchild == NULL && x->lchild != NULL)
        x->height = x->lchild->height + 1;
    else if(x->rchild != NULL && x->lchild == NULL)
        x->height = x->rchild->height + 1;
    else if(x->rchild == NULL && x->lchild == NULL)
        x->height = 1;
    else
    {
        x->height = x->lchild->height > x->rchild->height ? x->lchild->height + 1 : x->rchild->height + 1;
    }
    return x;
}
AVLNode* AVLTree::RR(AVLNode *y)
{
    AVLNode* x = y->rchild;
    y->rchild = x->lchild;
    x->lchild = y;
    //y
    if(y->rchild == NULL && y->lchild != NULL)
        y->height = y->lchild->height + 1;
    else if(y->rchild != NULL && y->lchild == NULL)
        y->height = y->rchild->height + 1;
    else if(y->rchild == NULL && y->lchild == NULL)
        y->height = 1;
    else
    {
        y->height = y->lchild->height > y->rchild->height ? y->lchild->height + 1 : y->rchild->height + 1;
    }
    //x
    if(x->rchild == NULL && x->lchild != NULL)
        x->height = x->lchild->height + 1;
    else if(x->rchild != NULL && x->lchild == NULL)
        x->height = x->rchild->height + 1;
    else if(x->rchild == NULL && x->lchild == NULL)
        x->height = 1;
    else
    {
        x->height = x->lchild->height > x->rchild->height ? x->lchild->height + 1 : x->rchild->height + 1;
    }
    return x;
}
AVLNode* AVLTree::LR(AVLNode *y)
{
    AVLNode *x = y->lchild;
    y->lchild = RR(x);
    return LL(y);
}
AVLNode* AVLTree::RL(AVLNode *y)
{
    AVLNode *x = y->rchild;
    y->rchild = LL(x);
    return RR(y);
}
void AVLTree::Inorder_Traversal()
{
    Inorder_Traversal(rt); cout << endl;
}
void AVLTree::Inorder_Traversal(AVLNode *t)
{
    if(t->lchild != NULL)
        Inorder_Traversal(t->lchild);
    int bf = CalcBF(t);
    cout << t->data << ":" << bf << " ";
    if(t->rchild != NULL)
        Inorder_Traversal(t->rchild);
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        AVLTree tree;
        int n = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int d = 0;
            cin >> d;
            tree.rt = tree.InsertTree(tree.rt, d);
        }
        tree.Inorder_Traversal();
    }
    return 0;
}
/*
8
3
64 5 1
3
64 5 13
6
64 78 5 1 13 15
6
64 78 5 1 13 10
3
64 78 100
3
64 80 70
6
64 30 80 90 70 68
6
64 30 80 90 70 75
*/