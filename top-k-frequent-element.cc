#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (auto n : nums)
        freq[n]++;
    vector<pair<int, int>> vec;
    for (auto p : freq)
        vec.push_back(p);
    auto comp = [](pair<int, int> _a, pair<int, int> _b)
    {
        return _a.second > _b.second;
    };
    sort(vec.begin(), vec.end(), comp);
    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.push_back(vec[i].first);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
}