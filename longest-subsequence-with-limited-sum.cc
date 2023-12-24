#include <bits/stdc++.h>
using namespace std;

// function with custom binary search
vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    sort(nums.begin(), nums.end());
    vector<int> psum(nums.size());
    psum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
        psum[i] = psum[i - 1] + nums[i];

    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        int start = 0;
        int end = psum.size() - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (psum[mid] > queries[i])
                end = mid - 1;
            else
            {
                if (start == mid)
                    start = mid + 1;
                else
                    start = mid;
            }
        }
        if (psum[start] <= queries[i])
            ans.push_back(start + 1);
        else
            ans.push_back(start);
    }
    return ans;
}

// using upper_bound()
vector<int> answerQueries2(vector<int> &nums, vector<int> &queries)
{
    sort(nums.begin(), nums.end());
    vector<int> psum(nums.size());
    psum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
        psum[i] = psum[i - 1] + nums[i];

    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        auto it = upper_bound(psum.begin(), psum.end(), queries[i]);
        ans.push_back(it - psum.begin());
    }
    return ans;
}

int main()
{
    vector<int> v = {2, 3, 4, 5};
    vector<int> q = {1, 3, 5, 7, 9, 15};
    vector<int> o = answerQueries2(v, q);
    for (auto val : o)
        cout << val << " ";
    cout << endl;
}