#include <iostream>
#include <queue>
using namespace std;

// int a[110];
queue<pair<int, int>> qu;
int main()
{
    int n = 0, i = 0;
    cin >> n;
    pair<int, int> temp;
    int count = 1;
    cin >> temp.first;
    qu.push(temp);
    qu.back().second = 1;
    int tempcount = 1;
    while (cin >> temp.first)
    {
        if (tempcount != -1 && temp.first > qu.back().first)
        {
            qu.push(temp);
            qu.back().second = ++count;
            tempcount++;
        }
        else if(tempcount != -1 && temp.first <= qu.back().first)
            count++;
        if (tempcount == 5)
        {
            tempcount = -1;
            continue;
        }

        if (tempcount == -1 && temp.first > qu.back().first)
        {
            qu.pop();
            qu.push(temp);
            qu.back().second = ++count;
        }
        else if(tempcount == -1 && temp.first <= qu.back().first)
            count++;
    }
    while (!qu.empty())
    {
        cout << qu.front().second << " ";
        qu.pop();
    }
    return 0;
}