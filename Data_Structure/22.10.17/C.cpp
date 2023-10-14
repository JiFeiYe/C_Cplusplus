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
    void Postorder_NonRecursive();//非递归后序遍历
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
void BiTree::Postorder_NonRecursive()
{
    stack<BiTNode*> s;
    BiTNode *cur;
    BiTNode *pre = NULL;
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
        tree.Postorder_NonRecursive();
        cout << endl;
    }
    return 0;
}