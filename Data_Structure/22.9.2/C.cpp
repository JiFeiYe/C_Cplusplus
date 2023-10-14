#define error -1
#include<iostream>
using namespace std;

class Selist
{
    int *list;
    int size;
    const int maxsize = 1000;
public:
    Selist(){size = 0; list = new int[maxsize];}
    ~Selist(){delete []list;}
    int mix(int n, int *list_n, int m, int *list_m)
    {
        if(n + m <= maxsize)
        {
            int index1 = 0, index2 = 0;
            int index3 = 0;
            while(index1 != n && index2 != m)
            {
                if(list_n[index1] < list_m[index2])
                {
                    list[index3++] = list_n[index1++];
                    size++;
                }
                else
                {
                    list[index3++] = list_m[index2++];
                    size++;
                }
            }
            while(index1 < n){list[index3++] = list_n[index1++]; size++;}
            while(index2 < m){list[index3++] = list_m[index2++]; size++;}
            this->display();
            return 0;
        }
        else
        {
            return error;
        }
    }
    void display()
    {
        cout << size << " ";
        for(int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 0, m = 0;
    cin >> n;
    int *list1 = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> list1[i];
    }
    cin >> m;
    int *list2 = new int[m];
    for(int i = 0; i < m; i++)
    {
        cin >> list2[i];
    }
    Selist sl;
    if(sl.mix(n, list1, m, list2) == error)
    {
        cout << "error" << endl;
    }
    delete []list1;
    delete []list2;
    return 0;
}