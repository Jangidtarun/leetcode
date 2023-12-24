#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    vector<int> psum(nums.size());
    psum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
        psum[i] = psum[i - 1] + nums[i];
    return psum;
}

int main()
{
}