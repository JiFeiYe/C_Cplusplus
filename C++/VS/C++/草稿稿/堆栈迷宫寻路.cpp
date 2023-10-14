//#include<iostream>
//#include<stack>
//using namespace std;
//#define error 1
//
//// class Coordinates
//// {
//// public:
////     int x;
////     int y;
////     bool state;
////     Coordinates(int x_, int y_)
////     {
////         x = x_; y = y_; state = 0;
////     }
////     void stste_change(bool state_)
////     {
////         state = state_;
////     }
////     int state_check()
////     {
////         if(state)
////             return true;
////         return false;
////     }
//// };
//struct Coordinate
//{
//    int x;
//    int y;
//}co;
////往下走、往上回 == -1；
////往右走、往左回 == -2；
////往上走、往下回 == -3；
////往左走、往右回 == -4；
////不可走 == 1；
//int path(int** p, int n)
//{
//    int x = 0, y = 0;
//    stack <Coordinate> s1;
//    co.x = x; co.y = y;
//    s1.push(co);
//    while (1)
//    {
//        if (x == n - 1 && y == n - 1)
//        {
//            break;
//        }
//
//        if (y + 1 < n && p[x][y + 1] != 1)//往右
//        {
//            p[x][++y] = -2;
//            co.x = x; co.y = y;
//            s1.push(co);
//        }
//        else if (x + 1 < n && p[x + 1][y] != 1)//往下
//        {
//            p[++x][y] = -1;
//            co.x = x; co.y = y;
//            s1.push(co);
//        }
//
//        else if (y - 1 >= 0 && p[x][y - 1] != 1)//往左
//        {
//            p[x][--y] = -4;
//            co.x = x; co.y = y;
//            s1.push(co);
//        }
//        else if (x - 1 >= 0 && p[x - 1][y] != 1)//往上
//        {
//            p[--x][y] = -3;
//            co.x = x; co.y = y;
//            s1.push(co);
//        }
//        else//无路可走
//        {
//            if (s1.empty())
//            {
//                return error;
//            }
//            else if (p[s1.top().x][s1.top().y] == -1)//往下走、往上回 == -1；
//            {
//                s1.pop();
//                p[x][y] = 1;
//                x--;
//            }
//            else if (p[s1.top().x][s1.top().y] == -2)//往右走、往左回 == -2；
//            {
//                s1.pop();
//                p[x][y] = 1;
//                y--;
//            }
//            else if (p[s1.top().x][s1.top().y] == -3)//往上走、往下回 == -3；
//            {
//                s1.pop();
//                p[x][y] = 1;
//                x++;
//            }
//            else if (p[s1.top().x][s1.top().y] == -4)//往左走、往右回 == -4；
//            {
//                s1.pop();
//                p[x][y] = 1;
//                y++;
//            }
//        }
//    }
//    stack <Coordinate> s2;
//    while (!s1.empty())
//    {
//        s2.push(s1.top());
//        s1.pop();
//    }
//    int endlcount = 0;
//    while (!s2.empty())
//    {
//        cout << "[" << s2.top().x << "," << s2.top().y << "]--";
//        s2.pop();
//        if (++endlcount == 4)
//        {
//            cout << endl;
//            endlcount = 0;
//        }
//    }
//    cout << "END" << endl;
//    return 0;
//}
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    int n = 0;
//    bool state = false;
//    while (t--)
//    {
//        cin >> n;
//        int** a = new int* [n];
//        for (int i = 0; i < n; i++)
//        {
//            a[i] = new int[n];
//        }
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                cin >> a[i][j];
//            }
//        }
//        if (path(a, n))
//            cout << "no path" << endl;
//    }
//    return 0;
//}