#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
bool pres1[N], pres2[N];

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    for (int i = 0; i < N; i++)
        pres1[i] = pres2[i] = false;

    for (int val : nums1)
        pres1[val + 1000] = true;
    for (int val : nums2)
        pres2[val + 1000] = true;

    vector<vector<int>> ans(2);
    for (int i = 0; i < N; i++)
        if (!pres2[i] and pres1[i])
            ans[0].push_back(i - 1000);

    for (int i = 0; i < N; i++)
        if (pres2[i] and !pres1[i])
            ans[1].push_back(i - 1000);

    return ans;
}

int main()
{
}