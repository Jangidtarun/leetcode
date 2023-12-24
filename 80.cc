#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size())
        return nums.size();
    int counter = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] == nums[i - 1])
            counter++;
        else
            counter = 0;
        if (counter > 2)
            nums.erase(nums.begin() + i);
    }
    return nums.size();
}

int main()
{
    vector<int> nums = {1, 1};
    int ans = removeDuplicates(nums);
    cout << ans << endl;
    for (auto val : nums)
        cout << val << " ";
    cout << endl;
}