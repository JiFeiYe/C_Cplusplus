//#include<iostream>
//#include<iomanip>
//#include<cstring>
//#include<cmath>
//using namespace std;
//
//class CXGraph
//{
//private:
//    int n;
//public:
//    CXGraph();
//    CXGraph(int n_);
//    CXGraph(const CXGraph& cr);
//    friend ostream& operator<<(ostream& stream, CXGraph cr);
//    CXGraph& operator++();//++a
//    CXGraph operator++(int);//a++
//    CXGraph& operator--();//--a
//    CXGraph operator--(int);//a--
//};
//CXGraph::CXGraph()
//{
//    n = 0;
//}
//CXGraph::CXGraph(int n_)
//{
//    n = n_;
//}
//CXGraph::CXGraph(const CXGraph& cr)
//{
//    n = cr.n;
//}
//ostream& operator<<(ostream& stream, CXGraph cr)
//{
//    int temp = (cr.n - 1) / 2;//(9-1)/2=4
//    int sum = (cr.n + 1) / 2;//×ÜÊý(9+1)/2=5
//    for (int i = 0; i <= temp; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            stream << " ";
//        }
//        for (int j = i; j < cr.n - 2 * i; j++)
//        {
//            stream << "X";
//        }
//        stream << endl;
//    }
//    for (int i = temp - 1; i >= 0; i--)
//    {
//        for (int j = i; j > 0; j--)
//        {
//            stream << " ";
//        }
//        for (int j = cr.n - 2 * i; j > 0; j--)
//        {
//            stream << "X";
//        }
//        stream << endl;
//    }
//    return stream;
//}
//CXGraph& CXGraph::operator++()//++a
//{
//    n++;
//    return *this;
//}
//CXGraph CXGraph::operator++(int)//a++
//{
//    CXGraph temp(*this);
//    n++;
//    return temp;
//}
//CXGraph& CXGraph::operator--()//--a
//{
//    n--;
//    return *this;
//}
//CXGraph CXGraph::operator--(int)//a--
//{
//    CXGraph temp(*this);
//    n--;
//    return temp;
//}
//
//int main()
//{
//    int t, n;
//    string command;
//    cin >> n;
//    CXGraph xGraph(n);
//    cin >> t;
//    while (t--)
//    {
//        cin >> command;
//        if (command == "show++")
//        {
//            cout << xGraph++ << endl;
//        }
//        else if (command == "++show")
//        {
//            cout << ++xGraph << endl;
//        }
//        else if (command == "show--")
//        {
//            cout << xGraph-- << endl;
//        }
//        else if (command == "--show")
//        {
//            cout << --xGraph << endl;
//        }
//        else if (command == "show")
//        {
//            cout << xGraph << endl;
//        }
//    }
//    return 0;
//}
