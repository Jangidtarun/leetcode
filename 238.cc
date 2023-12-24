#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int prefix[nums.size()];
    int suffix[nums.size()];
    prefix[0] = 1;
    suffix[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
        suffix[i] = suffix[i - 1] * nums[nums.size() - i];
    }
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
        ans[i] = prefix[i] * suffix[nums.size() - i - 1];
    return ans;
}