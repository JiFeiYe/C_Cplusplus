#include <iostream>
using namespace std;

int a[100] = {1, 5, 9, 11, 22, 23, 25, 30, 48, 50, 66, 67, 68, 70, 81};
// int a[50] = {81, 70, 68, 67, 66, 50, 48, 30, 25, 23, 22, 11, 9, 5, 1, 0};

// 二分查找
int search(int left, int right, int num)
{
    int ans = -1;
    while (left < right)
    {
        int mid = left + right >> 1;
        if (num > a[mid])
            left = mid + 1;
        else if (num < a[mid])
            right = mid;
        else
            return mid;
        ans = left;
    }
    return ans;
}

int main()
{
    printf("%d\n", search(0, 15, 900));
    std::cout << __cplusplus << endl;
    return 0;
}