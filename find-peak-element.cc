#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        int lvalue = INT_MIN, rvalue = INT_MIN;
        if (mid != 0)
            lvalue = nums[mid - 1];
        if (mid != nums.size() - 1)
            rvalue = nums[mid + 1];

        if (nums[mid] > lvalue and nums[mid] > rvalue)
            return mid;

        if (nums[mid] >= lvalue and nums[mid] < rvalue)
            start = mid + 1;

        else if (nums[mid] < lvalue)
        {
            if (nums[mid] > rvalue)
                end = mid - 1;
            else if (nums[mid] < rvalue)
            {
                if (rvalue > lvalue)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
    }
    return start;
}

int main()
{
    vector<int> v = {1, 2, 1, 3, 5, 6, 8};
    int ind = findPeakElement(v);
    cout << ind << endl;
}