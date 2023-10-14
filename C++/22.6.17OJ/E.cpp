#include<iostream>
#include<iomanip>
using namespace std;

class CBook
{
private:
    string name, editor;
    double price;
    string publish;
public:
    double getvalue();
    friend ostream& operator<<(ostream& stream, CBook& cb);
    friend istream& operator>>(istream& stream, CBook& cb);
    friend void find(CBook *book, int n, int &max1index,int &max2index);
};
double CBook::getvalue()
{
    return price;
}
ostream& operator <<(ostream& stream, CBook& cb){
    stream << cb.name << endl << cb.editor << endl << fixed << setprecision(2) << cb.price << endl << cb.publish << endl;
    return stream;
}
istream& operator>>(istream& stream, CBook& cb){
    stream >> cb.name >> cb.editor >> cb.price >> cb.publish;
    return stream;
}
void find(CBook *book, int n, int &max1index, int &max2index)
{
    double max = 0;
    max1index = 0;
    max2index = 0;
    for(int i = 0; i < n; i++)
    {
        if(max < book[i].getvalue())
        {
            max = book[i].getvalue();
            max1index = i;
        }
    }
    max = 0;
    for(int i = 0; i < n; i++)
    {
        if(max < book[i].getvalue() && i != max1index)
        {
            max = book[i].getvalue();
            max2index = i;
        }
    }
    return;
}

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    string name = " ", editor = " ", publish = " ";
    double price = 0;
    int max1index = 0, max2index = 0;
    while(t--)
    {
        cin >> n;
        CBook* cb = new CBook[n];
        for(int i = 0; i < n; i++)
        {
            cin >> cb[i];
        }
        find(cb, n, max1index, max2index);
        cout << cb[max1index] << endl << cb[max2index];
    }
    return 0;
}