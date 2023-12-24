#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int ans = 0;
    vector<bool> visited(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++)
        visited[nums[i]] = true;
    for (int i = 0; i <= nums.size(); i++)
        if (!visited[i])
            ans = i;
    return ans;
}

int main()
{
}