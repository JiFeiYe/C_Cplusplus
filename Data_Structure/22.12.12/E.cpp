#include<iostream>
#include<queue>
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
    string s1;
    string s2;
    int count;
public:
    BiTree(string s, string s_){s1 = s; s2 = s_;}
    BiTree(){rt = NULL;}
    ~BiTree(){delete rt;}
    void CreatTree();//先序创建二叉树
    void CreatTree(BiTNode *&t, BiTNode *p);
    void BFS();
};
void BiTree::CreatTree()
{
    count = s2.size();
    CreatTree(rt, NULL);
}
void BiTree::CreatTree(BiTNode *&t, BiTNode *p)
{
    char c = s2[0];
    for(int i = 0; i < count; i++)
        s2[i] = s2[i+1];
    if(c == '#')
    {
        t = new BiTNode('#');
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
void BiTree::BFS()
{
    int i = 0;
    BiTNode *p;
    queue <BiTNode*> Q;
    Q.push(rt);
    int size = s1.size();
    while(i != size)
    {
        p = Q.front();
        Q.pop();
        if(p)
        {
            if(p->data != s1[i])
            {
                cout << "NO" << endl;
                return;
            }
            Q.push(p->lchild);
            Q.push(p->rchild);
        }
        i++;
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if(s2[s2.size()] != '#')
            s2 += "##";
        BiTree tree(s1, s2);
        tree.CreatTree();
        tree.BFS();
    }
    return 0;
}