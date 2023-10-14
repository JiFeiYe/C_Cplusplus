#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

class Vehicle
{
protected:
    string no;
public:
    Vehicle(string no_){
        no = no_;
    }
    virtual void display() = 0; //收费
};

class CCar:public Vehicle
{
private:
    int number;
    int weight;
public:
    CCar(string no, int num_, int wei_):Vehicle(no){
        number = num_; weight = wei_;
    }
    void display(){
        cout << no << " ";
        cout << number*8 + weight*2 << endl;
    }
};

class CTruck:public Vehicle
{
private:
    int weight;
public:
    CTruck(string no, int wei_):Vehicle(no){
        weight = wei_;
    }
    void display(){
        cout << no << " ";
        cout << weight*5 << endl;
    }
};

class CBus:public Vehicle
{
private:
    int number;
public:
    CBus(string no, int num_):Vehicle(no){
        number = num_;
    }
    void display(){
        cout << no << " ";
        cout << number*30 << endl;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    int type = 0;
    string no = " ";
    int number = 0, weight = 0;
    Vehicle* pv;
    while(t--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> no >> number >> weight;
            CCar car(no, number, weight);
            pv = &car;
            pv->display();
            
        }
        else if(type == 2)
        {
            cin >> no >> weight;
            CTruck truck(no, weight);
            pv = &truck;
            pv->display();
        }
        else if(type == 3)
        {
            cin >> no >> number;
            CBus bus(no, number);
            pv = &bus;
            pv->display();
        }
        else
        {
            cout << "error" << endl;
        }
    }
    return 0;
}