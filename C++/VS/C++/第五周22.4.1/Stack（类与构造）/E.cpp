#include <iostream>
using namespace std;

class CStack
{
private:
	int top;
	int size;//栈大小
	int* a;//指向栈顶
public:
	CStack();//建立一个十元素的栈
	CStack(int s);//建立一个有s个元素的栈
	int get(int index);//返回下标为index的栈元素
	void push(int n);//进栈，top加一，把n的值存入栈顶
	int pop();//出栈，返回栈顶函数，top减1
	int isEmpty();//判断栈是否是空的，空则返回1，非空返回0
	int isFull();//判断栈是否是满的，满则返回1，否则返回0
	~CStack();//析构函数，释放在构造时申请的空间
};
CStack::CStack()
{
	top = 0;
	size = 10;
	a = new int[size];
	cout << "Constructor." << endl;
}
CStack::CStack(int s)
{
	top = 0;
	size = s;
	a = new int[size];
	cout << "Constructor." << endl;
}
int CStack::get(int index)
{
	return a[index];
}
void CStack::push(int n)
{
	a[top++] = n;
}
int CStack::pop()
{
	return a[--top];
}
int CStack::isEmpty()
{
	if (top == 0)
	{
		return 1;
	}
	return 0;
}
int CStack::isFull()
{
	if (top == size)
	{
		return 1;
	}
	return 0;
}
CStack::~CStack()
{
	delete[] a;
	cout << "Destructor." << endl;
}

int main()
{
	int t = 0, size = 0, element = 0;
	cin >> t;
	while (t--)
	{
		cin >> size;
		CStack Stack(size);
		for (int i = 0; i < size; i++)
		{
			cin >> element;
			Stack.push(element);
		}
		/*for (int i = 0; i < size; i++)
		{
			cout << Stack.pop() << " ";
		}*/
		cout << Stack.pop();
		while (Stack.isEmpty() == 0)
		{
			cout << " " << Stack.pop();
		}
		cout << endl;
	}
	return 0;
}