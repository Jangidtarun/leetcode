#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    vector<int> candies(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++)
        if (ratings[i] > ratings[i - 1] and candies[i] <= candies[i - 1])
            candies[i] = candies[i - 1] + 1;
    for (int i = ratings.size() - 2; i >= 0; i--)
        if (ratings[i] > ratings[i + 1] and candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    return accumulate(candies.begin(), candies.end(), 0);
}

int main()
{
    vector<int> v = {1, 2, 87, 87, 87, 2, 1};
    int ans = candy(v);
    cout << ans << endl;
}