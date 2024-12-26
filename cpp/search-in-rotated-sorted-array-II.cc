#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[mid] == nums[start] and nums[end] == nums[mid])
        {
            start++;
            end--;
        }

        else if (nums[mid] >= nums[start])
        {
            if (target >= nums[start] and nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        else
        {
            if (nums[mid] < target and nums[end] >= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return nums[start] == target;
}

int main()
{
    //                  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    vector<int> vals = {1, 2, 3};
    for (auto val : vals)
    {
        bool ans = search(nums, val);
        if (ans)
            cout << "found\n";
        else
            cout << "nope\n";
    }
}