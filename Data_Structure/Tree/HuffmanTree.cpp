//Huffman赫夫曼树，也称最优二叉树。
#include<iostream>
#include<queue>
using namespace std;

class HuffmanNode
{
    int weight;
    HuffmanNode *lchild;
    HuffmanNode *rchild;
    HuffmanNode *parent;//没用上
public:
    HuffmanNode()
    {
        lchild = NULL; rchild = NULL; parent = NULL;
    }
    HuffmanNode(int weight_)
    {
        weight = weight_; lchild = NULL; rchild = NULL; parent = NULL;
    }
    int getweight()
    {
        return weight;
    }
    friend class HuffmanTree;
};
struct cmp
{
    bool operator() (HuffmanNode *&a, HuffmanNode *&b)
    {
        return a->getweight() > b->getweight();
    }
};

priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp> pque;

class HuffmanTree
{
    HuffmanNode *rt;
public:
    HuffmanTree(){rt = NULL;}
    ~HuffmanTree(){delete rt;}
    void CreatTree();
    void Preorder_Traversal();
    void Preorder_Traversal(HuffmanNode *t);
};
void HuffmanTree::CreatTree()
{
    do
    {
        HuffmanNode *first = pque.top();
        pque.pop();
        if(pque.empty())//仅限第一次
        {
            rt = first;
            return;
        }
        HuffmanNode *rooot = new HuffmanNode;
        rooot->lchild = first;
        rooot->rchild = pque.top();
        rooot->weight = rooot->lchild->weight + rooot->rchild->weight;
        pque.pop();
        pque.push(rooot);
    } while (!pque.empty());
}
void HuffmanTree::Preorder_Traversal()
{
    Preorder_Traversal(rt);
}
void HuffmanTree::Preorder_Traversal(HuffmanNode *t)
{
    cout << t->weight << " ";
    if(t->lchild != NULL)
        Preorder_Traversal(t->lchild);
    if(t->rchild != NULL)
        Preorder_Traversal(t->rchild);
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        HuffmanTree htree;
        int n = 0;
        cin >> n;
        int weight;
        while(n--)
        {
            cin >> weight;
            HuffmanNode *t = new HuffmanNode(weight);
            pque.push(t);
        }
        htree.CreatTree();
        htree.Preorder_Traversal();
    }
    return 0;
}