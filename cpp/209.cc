#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int ans = INT_MAX, wsum = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        wsum += nums[i];
        if (wsum >= target)
        {
            while (wsum >= target and j <= i)
            {
                if (wsum - nums[j] >= target)
                {
                    wsum -= nums[j];
                    j++;
                }
                else
                    break;
            }
            ans = min(ans, i - j + 1);
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 11;
    int ans = minSubArrayLen(target, v);
    cout << ans << endl;
}