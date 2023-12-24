#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
private:
    queue<int> q;

public:
    vector<int> list;
    RecentCounter() {}

    int ping(int t)
    {
        if (q.empty())
        {
            q.push(t);
            return 1;
        }

        while (!q.empty() and t - q.front() > 3000)
            q.pop();
        q.push(t);

        return q.size();
    }
};

int main()
{
    RecentCounter *call1 = new RecentCounter();
    vector<int> input = {642, 1849, 4921, 5936, 5957};
    vector<int> output;
    for (int val : input)
        output.push_back(call1->ping(val));

    for (int val : output)
        cout << val << endl;
    cout << endl;
}