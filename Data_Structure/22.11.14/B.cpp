#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    double y = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> y;
        double x = y/2;
        double left = 0;
        double right = y;
        while(1)
        {
            if(abs(x*x-y) > 0.00001)
            {
                if(x*x > y)
                {
                    right = x;
                    x = (right+left)/2;
                }
                else
                {
                    left = x;
                    x = (right+left)/2;
                }
            }
            else
                break;
        }
        printf("%.3lf\n",x);
    }
    return 0;
}