#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};
    if (nums.size() == 0)
        return ans;

    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    if (nums[start] == target)
        ans[0] = start;
    start = 0, end = nums.size() - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }
    if (nums[start] == target)
        ans[1] = start;
    else if (start - 1 >= 0 and nums[start - 1] == target)
        ans[1] = start - 1;

    return ans;
}

int main()
{
    vector<int> nums = {2};
    int target = 2;
    vector<int> ans = searchRange(nums, target);
    cout << "start: " << ans[0] << " end: " << ans[1] << endl;
}