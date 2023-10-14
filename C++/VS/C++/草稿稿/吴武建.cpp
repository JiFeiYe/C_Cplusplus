//#include <iostream>
//#include<cmath>
//#include<stack>
//using namespace std;
//
//struct PATH
//{
//    int x;
//    int y;
//};
//
//int a[1001][1001];
//stack<PATH>path;
//stack<PATH>tpath;//临时栈 存放path的逆序
//void Fun(int a[1001][1001], int n)
//{
//    int x = 0, y = 0;//此时的坐标
//    //如果第一个坐标不是0，则不满足 不用往下判断
//    PATH curpos;
//    curpos.x = x, curpos.y = y;
//    path.push(curpos);
//    while (1)
//    {
//        //如果第一个不满足 break
//        if (a[0][0] == 1)
//        {
//            cout << "no path" << endl; //找不到路径输出no path
//            return;
//        }
//        //到达迷宫终点break
//        if (x == n - 1 && y == n - 1)
//        {
//            break;
//        }
//        //如果所有的路径都走不了 意味着出不了迷宫
//        if (x == n - 1 && a[x][y + 1] == 1 && a[x][y - 1] == 1)
//        {
//            cout << "no path" << endl; //找不到路径输出no path
//            return;
//        }
//        //如果所有的路径都走不了 意味着出不了迷宫
//        if (y < n - 1 && a[x][y + 1] == 1 && x < n - 1 && a[x + 1][y] == 1 && y >= 1 && a[x][y - 1] == 1)
//        {
//            cout << "no path" << endl; //找不到路径输出no path
//            return;
//        }
//        else
//        {
//            if (y < n - 1 && a[x][y + 1] == 0)//向右走
//            {
//                a[x][++y] = 5;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//            else if (x < n - 1 && a[x + 1][y] == 0)//向下走
//            {
//                a[++x][y] = 3;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//            else if (y >= 1 && a[x][y - 1] == 0)//向左走
//            {
//                a[x][--y] = 4;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//            else if (x < n - 1 && a[x + 1][y] == 0)//向下走
//            {
//                a[++x][y] = 3;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//
//            else
//            {
//                if (a[path.top().x][path.top().y] == 5 && !path.empty())//向左退
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    y--;
//                }
//                else if (a[path.top().x][path.top().y] == 3 && !path.empty())//向上退
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    x--;
//                }
//                else if (a[path.top().x][path.top().y] == 4 && !path.empty())//向右退
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    y++;
//                }
//                else if (a[path.top().x][path.top().y] == 3 && !path.empty())//向上退
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    x--;
//                }
//            }
//        }
//
//
//    }
//
//    //输出
//    if (!path.empty()) //找到路径
//    {
//        int i = 0;  //以下是输出路径的代码
//        for (int i = 0; !path.empty(); i++)
//        {
//            tpath.push(path.top());
//            path.pop();
//        }
//        while (!tpath.empty())
//        {
//            if ((++i) % 4 == 0)
//            {
//                cout << '[' << tpath.top().x << ',' << tpath.top().y << ']' << "--" << endl;
//            }
//            else
//            {
//                cout << '[' << tpath.top().x << ',' << tpath.top().y << ']' << "--";
//            }
//            tpath.pop();
//        }
//        cout << "END" << endl;
//    }
//    else
//    {
//        cout << "no path" << endl; //找不到路径输出no path
//    }
//
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    int n;
//    while (t--)
//    {
//        cin >> n;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                cin >> a[i][j];
//            }
//        }
//        Fun(a, n);
//    }
//    return 0;
//}