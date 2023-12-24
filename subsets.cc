#include <bits/stdc++.h>
using namespace std;

void generate_subset(vector<vector<int>> &alls, vector<int> &currs, int loc, vector<int> vec)
{
    if (loc == vec.size())
    {
        alls.push_back(currs);
        return;
    }

    generate_subset(alls, currs, loc + 1, vec);
    currs.push_back(vec[loc]);
    generate_subset(alls, currs, loc + 1, vec);
    currs.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> alls;
    vector<int> currs;
    generate_subset(alls, currs, 0, nums);
    return alls;
}

vector<vector<int>> _subsets_(vector<int> &nums)
{
    int n = nums.size();
    int nos = 1 << n;
    vector<vector<int>> ans;
    for (int mask = 0; mask < nos; mask++)
    {
        vector<int> sset;
        for (int bit = 0; bit < n; bit++)
            if (mask & 1 << bit)
                sset.push_back(nums[bit]);
        ans.push_back(sset);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = _subsets_(nums);
    for (auto vec : ans)
    {
        cout << "sub: ";
        for (auto val : vec)
            cout << val << " ";
        cout << endl;
    }
}