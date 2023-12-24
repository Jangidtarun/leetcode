#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    int ans = 0;
    int start = 0, end = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (start < end)
        if (nums[start] + nums[end] == k)
            start++, end--, ans++;
        else if (nums[start] + nums[end] > k)
            end--;
        else
            start++;
    return ans;
}

int main()
{
    vector<int> v = {3, 1, 3, 4, 3};
    int k = 6;
    int ans = maxOperations(v, k);
    cout << ans << endl;
}