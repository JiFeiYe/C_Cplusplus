#include<iostream>
using namespace std;

template <class T>
class list
{
private:
    T arr[100];
    int n;
public:
    list();
    list(T* arr_, int n_);
    void insert(int place, T value);
    void delete_(int place);
    void print();
};
template <class T>
list<T>::list()
{
    n = 100;
    for(int i = 0; i < 100; i++)
    {
        arr[i] = -1;
    }
}
template <class T>
list<T>::list(T* arr_, int n_)
{
    n = n_;
    for(int i = 0; i < n_; i++)
    {
        arr[i] = arr_[i];
    }
    for(int i = n_; i < 100; i++)
    {
        arr[i] = -1;
    }
}
template <class T>
void list<T>::insert(int place, T value)
{
    for(int i = n; i >= place; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[place] = value;
    n++;
}
template <class T>
void list<T>::delete_(int place)
{
    for(int i = place; i < n; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n] = -1;
    n--;
}
template <class T>
void list<T>::print()
{
    for(int i = 0; i < n-1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[n-1] << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    int* arr1 = new int[n];
    int place = 0, value1 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    list<int> l1(arr1, n);
    cin >> place >> value1;
    l1.insert(place, value1);
    cin >> place;
    l1.delete_(place);
    l1.print();
    //
    cin >> n;
    float* arr2 = new float[n];
    float value2 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    list<float> l2(arr2, n);
    cin >> place >> value2;
    l2.insert(place, value2);
    cin >> place;
    l2.delete_(place);
    l2.print();
    //system("pause");
    return 0;
}