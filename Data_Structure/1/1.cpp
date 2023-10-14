#include<iostream>
#include<queue>
#include<stack>
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
    void CreatTree();//先序创建二叉树
    void CreatTree(BiTNode *&t, BiTNode *p);
    void Preorder_Traversal();//先序遍历（递归算法）
    void Preorder_Traversal(BiTNode *t);
    void Inorder_Traversal();//中序遍历（递归算法）
    void Inorder_Traversal(BiTNode *t);
    void Postorder_Traversal();//后序遍历（递归算法）
    void Postorder_Traversal(BiTNode *t);
    void LevelOrder();//层次遍历（队列实现）
    void LevelOrder(BiTNode *t);
    void Inorder_NonRecursive();//非递归先序遍历
    void Postorder_NonRecursive();//非递归后序遍历（栈实现）
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
void BiTree::Inorder_NonRecursive()
{

}
void BiTree::Postorder_NonRecursive()
{
    stack<BiTNode*> s; //模拟程序递归栈
    BiTNode *cur; //当前访问节点
    BiTNode *pre = NULL; //记录前一个节点
    s.push(rt);
    while(!s.empty())
    {
        cur = s.top();
        if((cur->lchild == NULL && cur->rchild == NULL) || 
            (pre != NULL && (pre == cur->rchild || pre == cur->lchild)))
        {
            cout << cur->data;
            s.pop();
            pre = cur;
        }
        else
        {
            if(cur->rchild != NULL)
                s.push(cur->rchild);
            if(cur->lchild != NULL)
                s.push(cur->lchild);
        }
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
        tree.Preorder_Traversal();
        tree.Inorder_Traversal();
        tree.Postorder_Traversal();
        tree.LevelOrder();
        cout << endl;
        tree.Postorder_NonRecursive();
        cout << endl;
    }
    return 0;
}
/*
1
421##3##65##7##
*/