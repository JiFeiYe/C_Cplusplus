// 无括号的+-*/计算器，建树
#include <iostream>
#include <stack>
using namespace std;

char a[210];
stack<long long> s;
class TreeNode
{
public:
    char data;
    TreeNode *lchild;
    TreeNode *rchild;

public:
    TreeNode()
    {
        lchild = NULL;
        rchild = NULL;
    }
    TreeNode(char data_)
    {
        data = data_;
        TreeNode();
    }
    friend class Tree;
};
class Tree
{
    TreeNode *rt;
    TreeNode *p;
    long long n;

public:
    Tree(long long n_)
    {
        rt = NULL;
        p = NULL;
        n = 2 * n_ - 1;
    }
    void CreaTree();
    void CreaTree(TreeNode *&t, long long begin, long long end);
    void Postorder_Traversal();
    void Postorder_Traversal(TreeNode *t);
};
void Tree::CreaTree()
{
    CreaTree(rt, 0, n); // 左闭右开[0,n-1)
}
void Tree::CreaTree(TreeNode *&t, long long begin, long long end)
{
    if (begin == end - 1)
    {
        t = new TreeNode(a[begin]);
        t->lchild = NULL;
        t->rchild = NULL;
        return;
    }
    long long flag = 0;
    long long i = 0;
    for (i = end - 2; i > begin; i -= 2)
    {
        if (a[i] == '+' || a[i] == '-')
        {
            t = new TreeNode(a[i]);
            break;
        }
        if (i == begin + 1)
            flag = 1;
    }
    if (flag == 1)
        for (i = end - 2; i > begin; i -= 2)
        {
            if (a[i] == '*' || a[i] == '/')
            {
                t = new TreeNode(a[i]);
                break;
            }
        }
    CreaTree(t->lchild, begin, i);
    CreaTree(t->rchild, i + 1, end);
    return;
}
void Tree::Postorder_Traversal()
{
    Postorder_Traversal(rt);
}
void Tree::Postorder_Traversal(TreeNode *t)
{
    if (t->lchild != NULL)
        Postorder_Traversal(t->lchild);
    if (t->rchild != NULL)
        Postorder_Traversal(t->rchild);
    if (t->data == '+')
    {
        long long a = s.top();
        s.pop();
        long long b = s.top();
        s.pop();
        s.push(b + a);
    }
    else if (t->data == '-')
    {
        long long a = s.top();
        s.pop();
        long long b = s.top();
        s.pop();
        s.push(b - a);
    }
    else if (t->data == '*')
    {
        long long a = s.top();
        s.pop();
        long long b = s.top();
        s.pop();
        s.push(b * a);
    }
    else if (t->data == '/')
    {
        long long a = s.top();
        s.pop();
        long long b = s.top();
        s.pop();
        s.push(b / a);
    }
    else
    {
        if(t->data == ':')
            s.push(t->data - 48);
        else
            s.push(t->data);//注意辨别ASCII！！！
    }
}

int main()
{
    long long n = 0;
    cin >> n;
    for (long long i = 0; i < 2 * n - 1; i += 2)
    {
        int temp = 0;
        cin >> temp;
        if(temp == 10)
            a[i] = ':';
        else
            a[i] = temp;//直接赋值ASCII了！！！
    }
    for (long long i = 1; i < 2 * (n - 1); i += 2)
        cin >> a[i];
    Tree t(n);
    t.CreaTree();
    t.Postorder_Traversal();
    cout << s.top() << endl;
    return 0;
}
/*
4
1 2 3 4
+ * -
*/