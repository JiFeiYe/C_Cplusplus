#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    double n = 0;//测试数
    int k = 0;//进制
    stack <int> st;
    queue <int> qu;
    while(t--)
    {
        cin >> n >> k;
        int n_1 = n;//整数部分
        double n_2 = n - (double)n_1;//小数部分
        while(1)
        {
            st.push(n_1%k);
            n_1 /= k;
            if(n_1 == 1 || n_1== 0)
            {
                st.push(n_1);
                break;
            }
        }
        if(n_2 != 0)//有小数部分
        {
            for(int i = 0; i < 3; i++)
            {
                qu.push((int)(n_2*k));
                n_2 = (n_2*k) - (int)(n_2*k);
            }
        }
        else
        {
            
        }
        while(1)
        {
            if(st.top() == 0)
                st.pop();
            else
                break;
        }
        while(!st.empty())
        {
            if(st.top() <= 9)
            {
                cout << st.top();
                st.pop();
            }
            else if(st.top() >= 10)
            {
                cout << (char)(st.top()-10+'A');
                st.pop();
            }
        }
        cout << '.';
        while(!qu.empty())
        {
            if(qu.front() <= 9)
            {
                cout << qu.front();
                qu.pop();
            }
            else if(qu.front() >= 10)
            {
                cout << (char)(qu.front()-10+'A');
                qu.pop();
            }
        }
        cout << endl;
    }
    return 0;
}