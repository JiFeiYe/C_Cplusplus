#include<iostream>
#include<queue>
using namespace std;

struct client
{
    char type;
    int time;
};

int main()
{
    int n = 0;
    cin >> n;
    client *cli = new client[n];
    queue <client> myQA;
    for(int i = 0; i < n; i++)
    {
        cin >> cli[i].type;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> cli[i].time;
    }
    for(int i = 0; i < n; i++)
    {
        myQA.push(cli[i]);
    }
    int A = 0, B = 0, C = 0;
    int A_ = 0, B_ = 0, C_ = 0;
    for(int i = 0; i < n; i++)
    {
        if(myQA.front().type == 'A')
        {
            A += myQA.front().time;
            myQA.pop();
            A_++;
        }
        else if(myQA.front().type == 'B')
        {
            B += myQA.front().time;
            myQA.pop();
            B_++;
        }
        else if(myQA.front().type == 'C')
        {
            C += myQA.front().time;
            myQA.pop();
            C_++;
        }
    }
    cout << A/A_ << endl << B/B_ << endl << C/C_ << endl;
    delete []cli;
    return 0;
}