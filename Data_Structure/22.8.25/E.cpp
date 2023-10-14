#include<iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    char type = ' ';
    int n = 0;

    while(t--)
    {
        cin >> type >> n;
        if(type == 'I')
        {
            int* p = new int[n];
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                cin >> *(p+i);
            }
            for(int i = 0; i < n; i++)
            {
                sum += *(p+i);
            }
            cout << sum/n << endl;
        }
        else if(type == 'C')
        {
            char* p = new char[n];
            char ch = 'A';
            for(int i = 0; i < n; i++)
            {
                cin >> *(p+i);
            }
            for(int i = 0; i < n; i++)
            {
                if(ch <= *(p+i))
                {
                    ch = *(p+i);
                }
            }
            cout << ch << endl;
        }
        else if(type == 'F')
        {
            float* p = new float[n];
            float min = 9999999999;
            for(int i = 0; i < n; i++)
            {
                cin >> *(p+i);
            }
            for(int i = 0; i < n; i++)
            {
                if(min >= *(p+i))
                {
                    min = *(p+i);
                }
            }
            cout << min << endl;
        }
    }
    return 0;
}