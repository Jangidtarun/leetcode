#include <bits/stdc++.h>
using namespace std;

int maximumCount(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    if ((nums[start] < 0 and nums[end] < 0) or
        (nums[start] > 0 and nums[end] > 0))
        return nums.size();

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] < 0)
        {
            if (nums[end] < 0)
                start = end;
            else
            {
                if (start == mid)
                    end--;
                else
                    start = mid;
            }
        }
        else
            end = mid - 1;
    }

    if (start == end and nums[start] >= 0)
        start--;
    int neg = min(start, end) + 1;

    start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > 0)
            end = mid;
        else
            start = mid + 1;
    }
    if (nums[start] <= 0)
        start++;
    int pos = nums.size() - start;
    return max(neg, pos);
}

int main()
{
    // vector<int> v = {-3, -2, -1, 1, 2, 3, 4, 5, 6, 7};
    // vector<int> v = {0, 0, 1, 2, 3, 7};
    // vector<int> v = {-3, -2, -1, 0, 0, 0};
    vector<int> v = {-3, -2, -1, 0, 0, 0, 4, 5, 6, 7};
    int ans = maximumCount(v);
    cout << ans << endl;
}