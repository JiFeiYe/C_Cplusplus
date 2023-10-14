#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    int i = -1;
    unsigned u = 0u;
    cout << (i < u) << endl;
    cout << (2147483647u > (-2147483647 - 1)) << endl;
    cout << "---" <<endl;

    i = 0;
    u = 0u;
    cout << (i <= u - 1) << endl; //error
    cout << "---" << endl;

    char s[] = "a", t[] = "aaa";
    cout << (strlen(s) - strlen(t) > 0) << endl; //error
    cout << (strlen(s) > strlen(t)) << endl;
    cout << "---" <<endl;

    cout << (7 % 3) << endl;
    cout << ((-7) % (-3)) << endl;
    cout << ((-7) % 3) << endl;
    cout << (7 % (-3)) << endl;
    cout << "---" << endl;

    cout << (9 *16)%16 << endl;
    cout << (-9*16)%16 << endl;
    cout << "---" << endl;

    cout << (-12340 / (int)pow(2,4)) << endl;
    cout << (-12340 >> 4) << endl;
    cout << "---" << endl;
    return 0;
}