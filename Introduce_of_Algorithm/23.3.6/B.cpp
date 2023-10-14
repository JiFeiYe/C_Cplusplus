#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double R = 0, x = 0, y = 0;
    while (cin >> R)
    {
        cin >> x >> y;
        double len = sqrt(x * x + y * y);
        int i = 0;
        int temp = 0;
        for (i = 1; i * R <= len; i++)
        {
            temp++;
        }
        if ((i - 1) * R == len)
            i--;
        if(temp == 0)
            i++;
        cout << i << endl;
    }
    return 0;
}