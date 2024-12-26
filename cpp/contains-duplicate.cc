#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{

    int n = nums.size();
    unordered_set<int> m;
    m.insert(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (m.find(nums[i]) != m.end())
            return true;
        m.insert(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool ans = containsDuplicate(nums);
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}