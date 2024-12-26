#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    int minval = INT_MAX;
    stack<pair<int, int>> s;
    MinStack()
    {
    }

    void push(int val)
    {
        minval = min(val, minval);
        s.push({val, minval});
    }

    void pop()
    {
        s.pop();
        if (s.empty())
            minval = INT_MAX;
        else
            minval = s.top().second;
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};