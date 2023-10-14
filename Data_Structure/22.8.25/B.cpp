#include<iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    int num = 0;//查询序号
    int *p = NULL;//指针
    while(t--)
    {
        cin >> n;
        int *score = new int[n];//数组存成绩
        score[0] = 0;
        //输入数组
        for(int i = 0; i < n; i++)
        {
            cin >> score[i];
        }
        //指向数组中间元素
        if(n % 2 == 0)//偶数
        {
            p = score + (n/2);
            n = n/2;
        }
        else//奇数
        {
            p = score + ((n-1)/2);
            n = (n-1)/2;
        }
        int *temp = --p;
        p++;
        cout << *temp++ << " " << *++temp << endl;
        cin >> num;
        num--;
        cout << *(p+(num-n)) << endl;
        delete[] score;
    }
    return 0;
}