#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int i = 0, j = 1;
    unordered_map<int, int> s;
    s[nums[0]]++;
    while (j < nums.size())
    {
        while (j - i <= k and j < nums.size())
        {
            if (s.find(nums[j]) != s.end() and s[nums[j]] > 0)
                return true;
            s[nums[j++]]++;
        }
        s[nums[i++]]--;
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2};
    int k = 2;
    bool ans = containsNearbyDuplicate(v, k);
    cout << (ans ? "true\n" : "false\n");
}