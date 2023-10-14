#include <iostream>
#include <string.h>
using namespace std;

struct test_paper
{
	int ID;
	char ans1[100];
	char ans2[100];
	char ans3[100];
};

int OneJudge(char*& a1, char*& b1)
{
	float len1 = float(strlen(a1)), len2 = float(strlen(b1));
	float temp = 0;
	if (len1 > len2)
	{
		temp = len2;
		len2 = len1;
		len1 = temp;
	}
	float count = 0;
	for (int i = 0; i < len1; i++)
	{
		if (a1[i] == b1[i])
		{
			count++;
		}
	}
	float judge = 0;
	//judge = int(count / len1 + 0.5);
	//judge = count / len1;
	//if (judge+0.000001 >= 0.9)
	//{
	//	return 1;//�г�Ϯ
	//}
	judge = count;
	if (judge >= 0.9 * len1)
	{
		return 1;//�г�Ϯ
	}
	return 0;
}

int Compare(test_paper* aa, test_paper* bb)//����ID,��ans1��ans2��ans3���бȽ�
{
	char* Ans_a = aa->ans1, * Ans_b = bb->ans1;
	if (OneJudge(Ans_a,Ans_b))
	{
		return 1;
	}
	Ans_a = aa->ans2; Ans_b = bb->ans2;
	if (OneJudge(Ans_a, Ans_b))
	{
		return 2;
	}
	Ans_a = aa->ans3; Ans_b = bb->ans3;
	if (OneJudge(Ans_a, Ans_b))
	{
		return 3;
	}
	return 0;
}

int main()
{
	int t = 0;
	//test_paper *a = new test_paper[t];//�ṹ���������
	test_paper a[50];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> (a + i)->ID >> (a + i)->ans1 >> (a + i)->ans2 >> (a + i)->ans3;
	}
	int Compare_Result = 0;
	for (int i = 0; i < t - 1; i++)
	{
		for (int j = i + 1; j < t; j++)
		{
			Compare_Result = Compare((a + i), (a + j));//���س�Ϯ�����
			if (Compare_Result)//��Ϊ0����Ϯ
			{
				cout << (a + i)->ID << " " << (a + j)->ID << " " << Compare_Result << endl;
			}
		}
	}
	return 0;
}