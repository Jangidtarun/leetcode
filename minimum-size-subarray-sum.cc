#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    if (nums.size() == 1)
    {
        if (nums[0] == target)
            return 1;
        else
            return 0;
    }

    int first = 0, second = 1;
    int sum = nums[first];
    int ans = nums.size() + 1;
    if (sum == target)
        return 1;
    if (sum > target)
        ans = 1;
    sum += nums[second];
    while (second < nums.size())
    {
        if (sum > target)
        {
            ans = min(ans, second - first + 1);
            sum -= nums[first];
            first++;
        }
        else if (sum < target)
        {
            second++;
            if (second < nums.size())
                sum += nums[second];
            else
                break;
        }
        else
        {
            ans = min(ans, second - first + 1);
            second++;
            if (second < nums.size())
                sum += nums[second];
            else
                break;
        }
    }

    return ans == nums.size() + 1 ? 0 : ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 11;
    int ans = minSubArrayLen(target, v);
    cout << ans << endl;
}