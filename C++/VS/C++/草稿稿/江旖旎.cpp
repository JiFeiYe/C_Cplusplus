//#include<iostream>
//#include<string>
//using namespace std;
//class BiNode {
//	char data;
//	BiNode* lchild;
//	BiNode* rchild;
//	BiNode* parents;
//public:
//	BiNode() :lchild(NULL), rchild(NULL), parents(NULL) {}
//	BiNode(char data_) :data(data_), lchild(NULL), rchild(NULL), parents(NULL) {}
//	friend class BiTree;
//};
//class BiTree {
//	BiNode* rt;
//	int count;
//public:
//	BiTree() :rt(NULL), count(0) {}
//	void CreateTree();
//	void CreateTree(BiNode*& t, BiNode* p);
//	void getCount(BiNode* t);
//	void getCount();
//};
//void BiTree::CreateTree() {
//	CreateTree(rt, NULL);
//}
//void BiTree::CreateTree(BiNode*& t, BiNode* p) {
//	char c;
//	cin >> c;
//	if (c != '0') {
//		t = new BiNode(c);
//		t->parents = p;
//		CreateTree(t->lchild, t);
//		CreateTree(t->rchild, t);
//	}
//	else {
//		t = NULL;
//	}
//}
//void BiTree::getCount() {
//	getCount(rt);
//	cout << count << endl;
//}
//void BiTree::getCount(BiNode* t) {
//	
//	//若是为空则不操作。
//	if (t) {
//		//求的是左叶子数量。
//		if (t->lchild == NULL && t->rchild == NULL && t->parents->lchild == t && t->parents != NULL) {
//			count++;
//		}
//		getCount(t->lchild);
//		getCount(t->rchild);
//	}
//}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		BiTree tree;
//		tree.CreateTree();
//		tree.getCount();
//	}
//	return 0;
//}