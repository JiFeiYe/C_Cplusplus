#include<iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    int a[2][3];
    int *p1 = a[0];
    int *p2 = a[1];
    while(t--)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << *(p1+2) << " " << *(p2+2) << " " << endl;
        cout << *(p1+1) << " " << *(p2+1) << " " << endl;
        cout << *(p1) << " " << *(p2) << " " << endl;
    }
    return 0;
}