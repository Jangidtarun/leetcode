#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int dp[nums.size()+1];
    dp[0] = 0;
    for (int i = 1; i < nums.size(); i++)
        dp[i] = INT_MAX;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (dp[i] < INT_MAX)
            for (int j = 1 + i; j <= i + nums[i]; j++)
                if (j < nums.size())
                    dp[j] = min(dp[i] + 1, dp[j]);
        if (dp[nums.size() - 1] < INT_MAX)
            return dp[nums.size() - 1];
    }
    return dp[nums.size() - 1];
}