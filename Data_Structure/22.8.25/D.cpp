#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point
{
    double x, y;
public:
    Point(){x = 0; y = 0;}
    Point(double x_value, double y_value){x = x_value; y = y_value;}
    Point(const Point &p){x = p.x; y = p.y;}
    double getX(){return x;}
    double getY(){return y;}
    void setXY(double x1, double y1){
        x = x1; y = y1;
        cout << "Constructor." << endl;
    }
    void setX(double x_value){x = x_value;}
    void setY(double y_value){y = y_value;}
    ~Point(){cout << "Distructor." << endl;}
    double getDisTo(const Point &p){
        return sqrt(pow(x-p.x, 2) + pow(y - p.y, 2));//计算距离
    }
};

int main()
{
    int t = 0;
    cin >> t;
    int num = 0;
    double x = 0, y = 0;
    while(t--)
    {
        cin >> num;
        Point *p = new Point[num];
        for(int i = 0; i < num; i++)
        {
            cin >> x >> y;
            p[i].setXY(x, y);//输入xy
        }
        int index1 = 0, index2 = 1;
        double distance = p[0].getDisTo(p[1]);
        for(int i = 0; i < num-1; i++)
        {
            for(int j = i+1; j < num; j++)
            {
                if(distance < p[i].getDisTo(p[j]))
                {
                    distance = p[i].getDisTo(p[j]);
                    index1 = i; index2 = j;
                }
            }
        }
        cout << "The longeset distance is " << fixed << setprecision(2) << distance;
        cout << ",between p[" << index1 << "] and p[" << index2 << "]." << endl;
        delete[] p;
    }
}