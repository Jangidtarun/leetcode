#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    if (nums.size() == 1)
        return {to_string(nums[0])};
    vector<string> ans;
    int start = 0;
    for (int end = 1; end < nums.size(); end++)
    {
        int len = 0;
        while (end < nums.size() and nums[end - 1] == nums[end])
            len++, end++;
        if (len > 0)
        {
            ans.push_back(to_string(nums[start]));
            start = end;
            continue;
        }
        len = 0;
        while (end < nums.size() and nums[end - 1] + 1 == nums[end])
            len++, end++;
        if (len > 0)
        {
            // cout << "start: " << start << " end: " << end << '\n';
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
            start = end;
            continue;
        }

        // cout << "start: " << start << '\n';
        ans.push_back(to_string(nums[start]));
        start = end;
    }
    // cout << "start: " << start << '\n';
    if (start == nums.size() - 1)
        ans.push_back(to_string(nums[start]));
    return ans;
}

int main()
{
    vector<int> v = {0, 1};
    vector<string> ans = summaryRanges(v);
    for (auto val : ans)
        cout << val << '\n';
}