#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= ans[ans.size() - 1][1])
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
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
    vector<vector<int>> v = {{1, 3},
                             {6, 9}};
    vector<int> newint = {2, 5};
    vector<vector<int>> ans = insert(v, newint);
    printmat(ans);
}