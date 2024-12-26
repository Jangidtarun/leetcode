#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxc = *max_element(candies.begin(), candies.end());
    vector<bool> ans(candies.size());
    for (int i = 0; i < candies.size(); i++)
        ans[i] = candies[i] + extraCandies > maxc;
    return ans;
}

int main()
{
}