#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int len = nums.size();
    int prefixmin[len];
    int suffixmax[len];
    prefixmin[0] = nums[0];
    suffixmax[len - 1] = nums[len - 1];
    for (int i = 1; i < len; i++)
    {
        prefixmin[i] = min(nums[i], prefixmin[i - 1]);
        suffixmax[len - 1 - i] = max(nums[len - 1 - i], suffixmax[len - i]);
    }

    for (int i = 0; i < len; i++)
        if (prefixmin[i] < nums[i] and nums[i] < suffixmax[i])
            return true;
    return false;
}

int main()
{
    vector<int> v = {2, 4, -2, -3};
    bool ans = increasingTriplet(v);
    cout << (ans ? "yes" : "no") << endl;
}