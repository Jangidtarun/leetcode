#include <bits/stdc++.h>
using namespace std;

int pivotIndexold(vector<int> &nums)
{
    vector<int> front_psum(nums.size());
    vector<int> back_psum(nums.size());
    front_psum[0] = nums[0];
    back_psum[0] = nums[nums.size() - 1];
    for (int i = 1; i < nums.size(); i++)
    {
        front_psum[i] = front_psum[i - 1] + nums[i];
        back_psum[i] = back_psum[i - 1] + nums[nums.size() - (i + 1)];
    }

    for (int i = 0; i < nums.size(); i++)
        if (front_psum[i] == back_psum[nums.size() - (i + 1)])
            return i;
    return -1;
}

int pivotIndex(vector<int> &nums)
{
    vector<int> psum(nums.size());
    psum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
        psum[i] = psum[i - 1] + nums[i];

    for (int i = 0; i < nums.size(); i++)
        if (psum[i] - nums[i] == psum[nums.size() - 1] - psum[i])
            return i;
    return -1;
}

int main()
{
    vector<int> v = {1, 7, 3, 6, 5, 6};
    int ans = pivotIndex(v);
    cout << ans << endl;
}