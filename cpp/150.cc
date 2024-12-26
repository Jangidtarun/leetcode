#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

int evalRPN(vector<string> &tokens)
{

    stack<int> s;
    unordered_set<string> op = {"+", "-", "*", "/"};
    for (auto tmp : tokens)
    {
        if (op.find(tmp) != op.end())
        {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            if (tmp == "+")
                s.push(first + second);
            else if (tmp == "-")
                s.push(second - first);
            else if (tmp == "*")
                s.push(first * second);
            else if (tmp == "/")
                s.push(second / first);
        }
        else
            s.push(stoi(tmp));
    }
    return s.top();
}