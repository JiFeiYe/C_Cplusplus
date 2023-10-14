#include<iostream>
using namespace std;

#define ok 0
#define error -1

//顺序表定义
class SeList
{
private:
    int *list;//元素数组
    int maxsize;//顺序表最大长度
    int size;//顺序表实际长度
public:
    SeList(int *list_, int n);//构造函数
    ~SeList();//析构函数
    int list_size();//获取顺序表实际长度
    int list_insert(int i, int item);//插入一个元素，参数是插入的数值和位置
    int list_del(int i);//删除一个元素，参数是删除的位置
    int list_get(int i);//获取一个元素，参数是获取的位置
    void list_display();
};
SeList::SeList(int *list_, int n)
{
    maxsize = 1000;
    size = n;
    list = new int[maxsize];
    for(int i = 0; i < n; i++)
    {
        list[i] = list_[i];
    }
}
SeList::~SeList()
{
    delete []list;
}
int SeList::list_size()
{
    return size;
}
int SeList::list_insert(int i, int item)
{
    if(size >= maxsize || i > size+1 || i <= 0)
    {
        return error;
    }
    else
    {
        for(int j = size; j >= i-1; j--)
        {
            list[j+1] = list[j];
        }
        list[i-1] = item;
        size++;
        this->list_display();
        return ok;
    }
}
int SeList::list_del(int i)
{
    if(i > 0 && i <= size)
    {
        for(int j = i-1; j < size; j++)
        {
            list[j] = list[j+1];
        }
        size--;
        this->list_display();
        return ok;
    }
    else
    {
        return error;
    }
}
int SeList::list_get(int i)
{
    if(i > 0 && i <= size)
    {
        cout << list[i-1];
        return ok;
    }
    else
    {
        return error;
    }
}
void SeList::list_display()
{
    cout << size << " ";
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    int *list_ = new int[n];
    for(int j = 0; j < n; j++)
    {
        cin >> list_[j];
    }
    cout << n << " ";
    for(int j = 0; j < n; j++)
    {
        cout << list_[j] << " ";
    }
    cout << endl;
    SeList sl(list_, n);
    int i = 0, item = 0;
    for(int j = 0; j < 2; j++)
    {
        cin >> i >> item;
        if(sl.list_insert(i, item) == error)
        {
            cout << "error" << endl;
        }
    }
    for(int j = 0; j < 2; j++)
    {
        cin >> i;
        if(sl.list_del(i) == error)
        {
            cout << "error" << endl;
        }
    }
    for(int j = 0; j < 2; j++)
    {
        cin >> i;
        if(sl.list_get(i) == error)
        {
            cout << "error" << endl;
        }
    }
    return 0;
}