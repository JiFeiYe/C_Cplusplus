#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class CXGraph
{
private:
    int n;
public:
    CXGraph();
    CXGraph(int n_);
    CXGraph(const CXGraph& cr);
    friend ostream& operator<<(ostream& stream, CXGraph cr);
    CXGraph& operator++();//++a
    CXGraph operator++(int);//a++
    CXGraph& operator--();//--a
    CXGraph operator--(int);//a--
};
CXGraph::CXGraph()
{
    n = 0;
}
CXGraph::CXGraph(int n_)
{
    n = n_;
}
CXGraph::CXGraph(const CXGraph& cr)
{
    n = cr.n;
}
ostream& operator<<(ostream& stream, CXGraph cr)
{
    int temp = (cr.n-1)/2;//(9-1)/2=4//(5-1)/2=2
    int sum = (cr.n+1)/2;//总数(9+1)/2=5
    for(int i = 0; i <= temp; i++)
    {
        for(int j = 0; j < i; j++)
        {
            stream << " ";
        }
        if(i == 0)
        {
            stream << "X";
        }
        for(int j = 1; j < cr.n-2*i; j++)
        {
            stream << "X";
        }
        if(i != 0)
        {
            stream << "X";
        }
        stream << endl;
    }
    for(int i = temp-1; i >= 0; i--)
    {
        for(int j = i; j > 0; j--)
        {
            stream << " ";
        }
        for(int j = cr.n-2*i; j > 0; j--)
        {
            stream << "X";
        }
        stream << endl;
    }
    return stream;
}
CXGraph& CXGraph::operator++()//++a
{
    if(n != 21)
    {
        n += 2;
    }
    return *this;
}
CXGraph CXGraph::operator++(int)//a++
{
    CXGraph temp(*this);
    if(n != 21)
    {
        n += 2;
    }
    return temp;
}
CXGraph& CXGraph::operator--()//--a
{
    if(n != 1)
    {
        n -= 2;
    }
    return *this;
}
CXGraph CXGraph::operator--(int)//a--
{
    CXGraph temp(*this);
    if(n != 1)
    {
        n -=2;
    }
    return temp;
}

int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if(command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    system("pause");
    return 0;
}
