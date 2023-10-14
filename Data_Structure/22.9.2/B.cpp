#define error -1;
#include<iostream>
using namespace std;

class Seqlist
{
private:
    int *list;
    int size;
    int maxsize;
public:
    Seqlist(int n, int *list_){
        maxsize = 1000; 
        size = n; 
        list = new int[maxsize];
        for(int i = 0; i < n; i++)
        {
            list[i] = list_[i];
        }
        this->display();
        }
        ~Seqlist(){
            delete []list;
        }
    int mulitiinsert(int i, int n, int item[]){
            for(int j = size; j >= i-1; j--){
                list[j+n] = list[j]; 
            }
            int index = 0;
            for(int j = i-1; j < i-1+n; j++){
                list[j] = item[index];
                index++;
            }
            size += n;
            this->display();
            return 0;
            
    }
    int multidel(int i, int n)
    {
            for(int j = i-1; j <= size-1-n; j++){
                list[j] = list[j+n];
            }
            size -= n;
            this->display();
            return 0;
    }
    void display()
    {
        cout << size << " ";
        for(int j = 0; j < size; j++)
        {
            cout << list[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    int *list_ = new int[n];
    for(int j = 0; j < n; j++)
    {
        cin >> list_[j];
    }
    Seqlist sl(n, list_);
    int i = 0, k = 0;
    cin >> i >> k;
    int *item = new int[k];
    for(int j = 0; j < k; j++)
    {
        cin >> item[j];
    }
    sl.mulitiinsert(i, k, item);
    cin >> i >> k;
    sl.multidel(i, k);
    delete []list_;
    delete []item;
    return 0;
}