#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (prices[i] > prices[i - 1])
            ans += prices[i] - prices[i - 1];
    return ans;
}

int main() {}