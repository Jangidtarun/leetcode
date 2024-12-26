#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    if (nums[start] < target and start + 1 == nums.size())
        return start + 1;
    return start;
}

int main()
{
    vector<int> sigma = {1};
    int val = 1;
    int ans = searchInsert(sigma, val);
    cout << ans << endl;
}