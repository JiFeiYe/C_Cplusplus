/*
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char c1[20];
        char* p = c1;
        cin >> c1;
        int a[20];
        char ch;
        int t = 0, tmp1 = 0, tmp2 = 0;
        int* q = a;
        while (*(p + tmp1) != '\0')
        {
            tmp1++;
        }
        cout << "tmp1=" << tmp1 << endl;
        do {
            cin >> ch;
            *(q + tmp2) = ch - 48;
            tmp2++;
        } while (ch != '\0');
        tmp2--;
        cout << "tmp2=" << tmp2 << endl;
        char c2[20], * s = c2;
        for (int i = 0; i < tmp1; i++)
        {
            if (i % tmp2 == 0)
            {
                t = 0;
            }
            *(s + i) = *(p + i) + *(q + t);
            if (*(p + i) >= 65 && *(p + i) <= 90 && *(s + i) > 90)
            {
                *(s + i) -= 26;
            }
            if (*(p + i) >= 97 && *(p + i) <= 122 && *(s + i) > 122)
            {
                *(s + i) -= 26;
            }
            t++;
        }
        for (int i = 0; i < tmp1; i++)
        {
            cout << *(s + i);
        }
        cout << endl;
    }
}
*/