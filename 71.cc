#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string simplifyPath(string path)
{
    stack<string> s;
    for (int i = 0; i < path.length(); i++)
    {
        string tmp = "";
        while (i < path.length() and path[i] != '/')
            tmp += path[i], i++;
        if (tmp == ".." and !s.empty())
            s.pop();
        else if (tmp != "" and tmp != "." and tmp != "..")
            s.push(tmp);
    }
    string ans = "";
    stack<string> tmp;
    while (!s.empty())
        tmp.push(s.top()), s.pop();
    while (!tmp.empty())
        ans += "/" + tmp.top(), tmp.pop();
    if (ans == "")
        ans += "/";
    return ans;
}

int main()
{
    string path = "/../";
    string newpath = simplifyPath(path);
    cout << newpath << '\n';
}