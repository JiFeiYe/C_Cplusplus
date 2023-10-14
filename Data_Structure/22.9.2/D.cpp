#include<iostream>
using namespace std;

class Selist
{
    int *list;
    int size;
    const int maxsize = 1000;
public:
    Selist(int n, int* list_)
    {
        size = n;
        list = new int[n+1];
        for(int i = 0; i < size; i++)
        {
            list[i] = list_[i];
        }
        this->display();
    }
    ~Selist(){delete []list;}
    void shift(int flag, int m)
    {
        m = m % size;
        if(flag == 0)//左移0
        {
            while(m--)
            {
                int temp = list[0];
                for(int i = 0; i < size; i++)
                {
                    list[i] = list[i+1];
                }
                list[size-1] = temp;
            }
            this->display();
        }
        else if(flag == 1)//右移1
        {
            while(m--)
            {
                int temp = list[size-1];
                for(int i = size; i > 0; i--)
                {
                    list[i] = list[i-1];
                }
                list[0] = temp;
            }
            this->display();
        }
    }
    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    int *list_ = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> list_[i];
    }
    int flag = 0, m = 0;
    cin >> flag >> m;
    Selist sl(n, list_);
    sl.shift(flag, m);
    cin >> flag >> m;
    sl.shift(flag, m);
    delete []list_;
    return 0;
}