#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		//��̬�����ɼ�
		int n = 0;
		cin >> n;
		int* p = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> *(p + j);
		}
		//�м�Ԫ��
		int* mid = p;
		if (n % 2 == 0)
		{
			mid = p + (n / 2);
		}
		else
		{
			mid = p + ((n + 1) / 2) - 1;
		}
		//����м�ɼ���ǰһ�����һ���ɼ�
		mid--;
		cout << *(mid) << ' ';
		mid++;
		mid++;
		cout << *(mid) << endl;
		//��ѯ�ɼ�
		int n1 = 0;
		cin >> n1;
		cout << *(p + n1 - 1) << endl;
		delete[] p;
	}
	return 0;
}