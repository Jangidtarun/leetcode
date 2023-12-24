#include <bits/stdc++.h>
using namespace std;

bool isorted(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
            return false;
    }
    return true;
}

int minimumRightShifts(vector<int> &nums)
{
    if (isorted(nums))
        return true;

    int max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[max] < nums[i])
            max = i;
    }

    int k = nums.size() - max - 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp = nums[(i + k) % nums.size()];
        nums[(i + k) % nums.size()] = nums[i];
        nums[i] = tmp;
    }
}

int main() {}