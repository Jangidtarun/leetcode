#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[start] == nums[mid])
        {
            if (nums[end] == nums[mid])
            {
                start++;
                end--;
            }
            else if (nums[end] < nums[mid])
                start = mid + 1;
            else
                end = mid;
        }
        else if (nums[mid] > nums[start])
        {
            if (nums[end] < nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        else
        {
            if (nums[end] >= nums[mid])
                end = mid;
            else
                start = mid + 1;
        }
    }
    return nums[start];
}

int main()
{
    // vector<int> v = {3, 1, 3};
    vector<int> v = {2, 2, 2, 0, 1};
    int ans = findMin(v);
    cout << ans << endl;
}