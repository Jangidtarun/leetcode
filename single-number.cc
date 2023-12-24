#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> m;
    int single = 0;
    for (int i = 0; i < n; i++)
        m[nums[i]]++;
    for (auto f : m)
        if (f.second == 1)
            single = f.first;
    return single;
}

int main()
{
    vector<int> num = {2,2,1};
    cout << "num: " << singleNumber(num) << endl;
}