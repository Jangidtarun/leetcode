#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    map<vector<int>, bool> mtmp;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int left = 0, right = nums.size() - 1;
        vector<int> tmp;
        while (left < i and right > i)
        {
            if (nums[left] + nums[right] == -nums[i])
            {
                mtmp[{nums[left], nums[i], nums[right]}] = true;
                left++;
            }
            else if (nums[left] + nums[right] < -nums[i])
                left++;
            else if (nums[left] + nums[right] > -nums[i])
                right--;
        }
        // if (nums[left] + nums[right] == -nums[i])
        //     mtmp[{nums[left], nums[i], nums[right]}] = true;
    }
    for (auto v : mtmp)
        ans.push_back(v.first);
    return ans;
}

int main()
{
    vector<int> v = {0,0,0};
    vector<vector<int>> ans = threeSum(v);
    for (auto v : ans)
    {
        for (auto elem : v)
            cout << elem << " ";
        cout << endl;
    }
}