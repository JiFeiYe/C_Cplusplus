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
//stack<PATH>tpath;//��ʱջ ���path������
//void Fun(int a[1001][1001], int n)
//{
//    int x = 0, y = 0;//��ʱ������
//    //�����һ�����겻��0�������� ���������ж�
//    PATH curpos;
//    curpos.x = x, curpos.y = y;
//    path.push(curpos);
//    while (1)
//    {
//        //�����һ�������� break
//        if (a[0][0] == 1)
//        {
//            cout << "no path" << endl; //�Ҳ���·�����no path
//            return;
//        }
//        //�����Թ��յ�break
//        if (x == n - 1 && y == n - 1)
//        {
//            break;
//        }
//        //������е�·�����߲��� ��ζ�ų������Թ�
//        if (x == n - 1 && a[x][y + 1] == 1 && a[x][y - 1] == 1)
//        {
//            cout << "no path" << endl; //�Ҳ���·�����no path
//            return;
//        }
//        //������е�·�����߲��� ��ζ�ų������Թ�
//        if (y < n - 1 && a[x][y + 1] == 1 && x < n - 1 && a[x + 1][y] == 1 && y >= 1 && a[x][y - 1] == 1)
//        {
//            cout << "no path" << endl; //�Ҳ���·�����no path
//            return;
//        }
//        else
//        {
//            if (y < n - 1 && a[x][y + 1] == 0)//������
//            {
//                a[x][++y] = 5;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//            else if (x < n - 1 && a[x + 1][y] == 0)//������
//            {
//                a[++x][y] = 3;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//            else if (y >= 1 && a[x][y - 1] == 0)//������
//            {
//                a[x][--y] = 4;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//            else if (x < n - 1 && a[x + 1][y] == 0)//������
//            {
//                a[++x][y] = 3;
//                curpos.x = x, curpos.y = y;
//                path.push(curpos);
//            }
//
//            else
//            {
//                if (a[path.top().x][path.top().y] == 5 && !path.empty())//������
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    y--;
//                }
//                else if (a[path.top().x][path.top().y] == 3 && !path.empty())//������
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    x--;
//                }
//                else if (a[path.top().x][path.top().y] == 4 && !path.empty())//������
//                {
//                    path.pop();
//                    a[x][y] = 1;
//                    y++;
//                }
//                else if (a[path.top().x][path.top().y] == 3 && !path.empty())//������
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
//    //���
//    if (!path.empty()) //�ҵ�·��
//    {
//        int i = 0;  //���������·���Ĵ���
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
//        cout << "no path" << endl; //�Ҳ���·�����no path
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