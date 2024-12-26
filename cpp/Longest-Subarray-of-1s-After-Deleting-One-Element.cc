#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int k = 1;
    int start = 0, end = 0;
    int tmp = 0;
    int ans = end - start;
    while (start <= end and end < nums.size())
    {
        if (nums[end] == 0)
            tmp++;
        while (tmp > k)
        {
            if (nums[start] == 0)
                tmp--;
            start++;
        }
        end++;
        ans = max(ans, end - start);
    }
    return ans - k;
}

int main()
{
    vector<int> v = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    int ans = longestSubarray(v);
    cout << ans << endl;
}