#include <bits/stdc++.h>
using namespace std;

bool isPossibleDivide(vector<int> &nums, int k)
{
    if (nums.size() % k)
        return false;
    vector<bool> vis(nums.size(), false);
    sort(nums.begin(), nums.end());
    vis[0] = true;

    int p = 0;
    for (int i = 0; i < k; i++)
    {
        int s = 1;
        for (int j = 1; j < nums.size(); j++)
        {
            if (!vis[j] and nums[j] == nums[j - 1] + 1)
            {
                vis[j] = true;
                nums.erase(nums.begin() + j);
                s++;
                if (s == 4)
                {
                    p++;
                    break;
                }
            }
        }
    }
    if (p == k)
        return true;
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 6};
    int k = 4;

    bool ans = isPossibleDivide(nums, k);
    cout << (ans ? "true" : "false") << endl;
}