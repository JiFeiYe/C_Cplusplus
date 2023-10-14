#include<iostream>
#include<iomanip>
using namespace std;

class CVector
{
private:
    int* data;
    int n;
public:
    CVector();
    CVector(int* data_, int n_);
    void print();
    float Average();
    int getn()
    {
        return n;
    }
    int getdata(int i)
    {
        return data[i];
    }
    ~CVector();
};
CVector::CVector()
{
    n = 5;
    data = new int[5];
    int temp = 0;
    for(int i = 0; i < 5; i++)
    {
        data[i] = temp++;
    }
}
CVector::CVector(int* data_, int n_)
{
    n = n_;
    data = new int [n];
    for(int i = 0; i < n; i++)
    {
        data[i] = data_[i];
    }
}
void CVector::print()
{
    cout << data[0];
    for(int i = 1; i < n; i++)
    {
        cout  << " " << data[i];
    }
    cout << endl;
}
float CVector::Average()
{
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += data[i];
    }
    return sum/n;
}
CVector::~CVector()
{
    delete[] data;
}

class CStudent
{
private:
    string name;
    CVector score;
public:
    CStudent(string name1, int n1, int* a1);
    void print();
};
CStudent::CStudent(string name1, int n1, int* a1):name(name1),score(a1, n1){}
void CStudent::print()
{
    cout << name;
    int temp = score.getn();
    for(int i = 0; i < temp; i++)
    {
        cout << " " << score.getdata(i);
    }
    cout << " " << fixed <<setprecision(2) <<score.Average() << endl;
}

int main()
{
    string name = " ";
    int n = 0;
    int data[50];
    while(cin >> name)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        CStudent student(name, n, data);
        student.print();
    }
    return 0;
}