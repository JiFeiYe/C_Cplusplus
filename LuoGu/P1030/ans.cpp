// 洛谷 P1030 [NOIP2001 普及组] 求先序排列
#include <iostream>
#include <string>
using namespace std;

void DFS(string in, string post) // 找根，然后左右子树分别DFS
{
    printf("%c", post.back());
    int pos = in.find(post.back());
    if (post.length() >= 1)
        post.erase(post.length() - 1);
    if (post != "")
    {
        string a = in.substr(0, pos);
        string b = post.substr(0, in.substr(0, pos).length());
        DFS(in.substr(0, pos), post.substr(0, in.substr(0, pos).length()));
        if (in.substr(pos + 1).length() >= 1)
        {
            string c = in.substr(pos + 1);
            string d = post.substr(post.length() - in.substr(pos + 1).length());
            DFS(in.substr(pos + 1), post.substr(post.length() - in.substr(pos + 1).length()));
        }
    }
}

int main()
{
    string in, post;
    cin >> in >> post;
    DFS(in, post);
    return 0;
}