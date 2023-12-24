#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i]) != m.end())
            return ans = {m[nums[i]], i};
        m[target - nums[i]] = i;
    }
    return ans;
}