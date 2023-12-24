#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    sort(nums.begin(), nums.end());
    int ans = 1, k = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
            continue;
        if (nums[i - 1] + 1 == nums[i])
            k++;
        else
            k = 1;
        ans = max(ans, k);
    }
    return ans;
}

int main()
{
    // vector<int> v = {9};
    vector<int> v = {400, 4, 200, 1, 3, 2};
    int ans = longestConsecutive(v);
    cout << ans << '\n';
}