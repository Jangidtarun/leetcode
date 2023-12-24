#include <bits/stdc++.h>
using namespace std;

int dp[310][10010];
int func(int index, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (index < 0)
        return 0;
    if (dp[index][amount] != -1)
        return dp[index][amount];

    int ans = 0;
    for (int coin = 0; coin <= amount; coin += coins[index])
        ans += func(index - 1, amount - coin, coins);

    return dp[index][amount] = ans;
}

int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));
    return func(coins.size()-1, amount, coins);
}

int main()
{
}