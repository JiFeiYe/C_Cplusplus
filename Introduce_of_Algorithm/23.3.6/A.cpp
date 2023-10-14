#include<iostream>
#include <time.h>
using namespace std;

int main()
{
    long long N = 0, i = 1;
    cin >> N;
    int ans = -2;
    for(; i <= N; i = i << 2)
    {
        ans += 2;
    }
    if(N > (i >> 1))
        ans++;
    cout << ans << endl;
    return 0;
}
//1 2 4 8 16 32 64 128 256
//0 1 2 3 4  5  6  7   8