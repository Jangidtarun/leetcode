#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int visited[210] = {false};
    visited[nums[0] + 100] = true;
    int swap_with = 1;
    for (int i = 1; i < n; i++)
    {
        if (!visited[nums[i] + 100])
        {
            visited[nums[i] + 100] = true;
            swap(nums[swap_with], nums[i]);
            swap_with++;
        }
    }
    return swap_with;
}

int main() {}