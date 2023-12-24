#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[start])
        {
            if (nums[end] < nums[mid])
                start = mid + 1;
            else if (nums[end] > nums[mid])
                end = mid - 1;
        }
        else if (nums[mid] <= nums[start])
        {
            if (nums[end] > nums[mid])
                end = mid;
            else if (nums[end] < nums[mid])
                start = mid + 1;
        }
    }
    return nums[start];
}

int main()
{
    vector<int> v = {2, 1};
    int ans = findMin(v);
    cout << "min: " << ans << endl;
}