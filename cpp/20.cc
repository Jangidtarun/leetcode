#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s)
{
    unordered_map<char, int> m = {{'(', -1},
                                  {'[', -2},
                                  {'{', -3},
                                  {')', 1},
                                  {']', 2},
                                  {'}', 3}};
    stack<char> tmp;
    for (auto c : s)
    {
        if (!tmp.empty() and m[tmp.top()] + m[c] == 0 and m[tmp.top()] < m[c])
            tmp.pop();
        else
            tmp.push(c);
    }
    return tmp.empty();
}