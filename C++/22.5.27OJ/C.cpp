#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CMoney
{
private:
    int yuan;
    int jiao;
    int fen;
public:
    CMoney(int, int, int);
    friend CMoney& operator+(CMoney& A, CMoney& B);
    friend CMoney& operator-(CMoney& A, CMoney& B);
    friend ostream& operator<<(ostream& stream, CMoney& A);
    friend istream& operator>>(istream& stream, CMoney& A);
};
CMoney::CMoney(int y = 0, int j = 0, int f = 0)
{
    yuan = y; jiao = j; fen = f;
}
CMoney& operator+(CMoney& A, CMoney& B)
{
    int afen = 0, bfen = 0;
    afen = A.yuan*100 + A.jiao*10 + A.fen;
    bfen = B.yuan*100 + B.jiao*10 + B.fen;
    afen += bfen;
    A.yuan = afen / 100;
    afen -= 100*A.yuan;
    A.jiao = afen / 10;
    afen -= 10*A.jiao;
    A.fen = afen;
    return A;
}
CMoney& operator-(CMoney& A, CMoney& B)
{
    int afen = 0, bfen = 0;
    afen = A.yuan*100 + A.jiao*10 + A.fen;
    bfen = B.yuan*100 + B.jiao*10 + B.fen;
    afen -= bfen;
    A.yuan = afen / 100;
    afen -= 100*A.yuan;
    A.jiao = afen / 10;
    afen -= 10*A.jiao;
    A.fen = afen;
    return A;
}
ostream& operator<<(ostream& stream, CMoney& A)
{
    stream << A.yuan << "元" << A.jiao << "角" << A.fen << "分";
    return stream;
}
istream& operator>>(istream& stream, CMoney& A)
{
    stream >> A.yuan >> A.jiao >> A.fen;
    return stream;
}

int main()
{
    int t = 0, yuan = 0, jiao = 0, fen = 0;
    cin >> t;
    string s = " ";
    while(t--)
    {
        cin >> yuan >> jiao >> fen;
        CMoney cm(yuan, jiao, fen);
        while(1)
        {
            cin >> s;
            if(s == "add")
            {
                CMoney temp;
                cin >> temp;
                cm + temp;
            }
            else if(s == "minus")
            {
                CMoney temp;
                cin >> temp;
                cm - temp;
            }
            else if(s == "stop")
            {
                break;
            }
        }
        cout << cm << endl;
    }
    return 0;
}