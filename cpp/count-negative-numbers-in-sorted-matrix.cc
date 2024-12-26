#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        auto itu = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
        count += itu - grid[i].rbegin();
    }
    return count;
}

int main()
{
    vector<int> v = {4, 3, 2, -1};
    sort(v.begin(), v.end());
    auto itl = lower_bound(v.begin(), v.end(), 0);
    auto itu = upper_bound(v.begin(), v.end(), 0);
    int first_negative_position = itu - v.begin();
    cout << first_negative_position << endl;
}