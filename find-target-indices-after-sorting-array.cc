#include <bits/stdc++.h>
using namespace std;

vector<int> targetIndices(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    auto it_lower = lower_bound(nums.begin(), nums.end(), target);
    auto it_upper = upper_bound(nums.begin(), nums.end(), target);
    int begin = it_lower - nums.begin();
    int end = it_upper - nums.begin();
    int n = end - begin;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = begin + i;
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 2, 3};
    vector<int> targ = targetIndices(nums, 5);
    for (auto val : targ)
        cout << val << " ";
    cout << endl;
}