#include<iostream>
#include<queue>
#define ok 1
#define error -1
using namespace std;

queue <int> que;

class HuffmanNode
{
    int weight;
    char ch;
    HuffmanNode *lchild;
    HuffmanNode *rchild;
public:
    HuffmanNode()
    {
        lchild = NULL; rchild = NULL;
    }
    HuffmanNode(int weight_, char ch_)
    {
        weight = weight_; ch = ch_; lchild = NULL; rchild = NULL;
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
};
void HuffmanTree::CreatTree()
{
    do
    {
        HuffmanNode *first = pque.top();
        pque.pop();
        if(pque.empty())
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
        char ch;
        while(n--)
        {
            cin >> weight;
            
            HuffmanNode *t = new HuffmanNode(weight, ch);
            pque.push(t);
            que.push(weight);
        }
        htree.CreatTree();
    }
    return 0;
}