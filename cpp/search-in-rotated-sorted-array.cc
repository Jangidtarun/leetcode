#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] >= nums[left])
            if (nums[left] <= target and nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        else
        {
            if (nums[right] >= target and nums[mid]  <= target)
                left = mid + 1;
            else
                right = mid;
        }
    }

    if (left == right)
        if (nums[left] == target)
            return left;
    return -1;
}

int main()
{
    vector<int> nums = {5, 1, 3};
    int target = 3;
    int ans = search(nums, target);
    if (ans == -1)
        cout << "not found\n";
    else
        cout << ans << endl;
}