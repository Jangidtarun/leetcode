#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    int ans = 0;
    vector<int> hash(110, 0);
    for (auto n : nums)
        hash[n]++;
    for (auto h : hash)
        ans += (h * (h - 1)) / 2;
    return ans;
}

int main()
{
}