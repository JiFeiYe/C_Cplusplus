#include<iostream>
using namespace std;

class OJ
{
private:
	int a;
public:
    OJ();
    OJ(int b);
    OJ(OJ& c);
    ~OJ(){};
};
OJ::OJ()
{
    a = 0;
    cout << "Constructed by default, value = " << a << endl;
}
OJ::OJ(int b)
{
    a = b;
    cout << "Constructed using one argument constructor, value = " << a << endl;
}
OJ::OJ(OJ& c)
{
    a = c.a;
    cout << "Constructed using copy constructor, value = " << a << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    int test = 0, a = 0;
    while(t--)
    {
        cin >> test;
        if(test == 0)
        {
            OJ oj;
        }
        else if(test == 1)
        {
            cin >> a;
            OJ oj(a);
        }
        else if(test == 2)
        {
            cin >> a;
            OJ oj(a);
            OJ oj_ = oj;
        }
    }
    return 0;
}