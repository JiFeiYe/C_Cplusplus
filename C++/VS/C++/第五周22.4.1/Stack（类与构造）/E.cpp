#include <iostream>
using namespace std;

class CStack
{
private:
	int top;
	int size;//ջ��С
	int* a;//ָ��ջ��
public:
	CStack();//����һ��ʮԪ�ص�ջ
	CStack(int s);//����һ����s��Ԫ�ص�ջ
	int get(int index);//�����±�Ϊindex��ջԪ��
	void push(int n);//��ջ��top��һ����n��ֵ����ջ��
	int pop();//��ջ������ջ��������top��1
	int isEmpty();//�ж�ջ�Ƿ��ǿյģ����򷵻�1���ǿշ���0
	int isFull();//�ж�ջ�Ƿ������ģ����򷵻�1�����򷵻�0
	~CStack();//�����������ͷ��ڹ���ʱ����Ŀռ�
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