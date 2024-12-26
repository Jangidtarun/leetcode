#include <bits/stdc++.h>
using namespace std;

int dp[2510];
int lis(int index, vector<int> &nums)
{
    if (dp[index] != -1)
        return dp[index];
    int ans = 1;
    for (int i = 0; i < index; i++)
        if (nums[i] < nums[index])
            ans = max(ans, lis(i, nums));
    return dp[index] = ans;
}

int lengthOfLIS(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans = max(ans, lis(i, nums));
    return ans;
}
