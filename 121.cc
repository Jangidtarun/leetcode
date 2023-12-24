#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0, minprice = prices[0];
    for (int i = 0; i < n - 1; i++)
    {
        minprice = min(minprice, prices[i]);
        ans = max(ans, prices[i + 1] - minprice);
    }
    return ans;
}

int main()
{
    vector<int> v = {4, 1, 2};
    int ans = maxProfit(v);
    cout << ans << endl;
}