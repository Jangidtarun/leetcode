#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 1)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int lastend = ans[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        lastend = ans[ans.size() - 1][1];
        if (intervals[i][0] <= lastend)
            ans[ans.size() - 1][1] = max(lastend, intervals[i][1]);
        else
            ans.push_back(intervals[i]);
    }
    return ans;
}

template <typename _tp>
void printmat(vector<vector<_tp>> &m)
{
    for (auto vec : m)
    {
        for (auto val : vec)
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    vector<vector<int>> v = {{1, 4}, {2, 3}};
    vector<vector<int>> ans = merge(v);
    printmat(ans);
}
