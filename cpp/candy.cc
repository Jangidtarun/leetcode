#include <bits/stdc++.h>
using namespace std;

vector<int> allmin(vector<int> &v)
{
    int min_val = v[0];
    vector<int> min_indexes;
    for (auto val : v)
        if (val < min_val)
            min_val = val;
    for (int i = 0; i < v.size(); i++)
        if (v[i] == min_val)
            min_indexes.push_back(i);
    return min_indexes;
}

int candy(vector<int> &ratings)
{
    auto i_min = min_element(ratings.begin(), ratings.end());
    vector<int> candies(ratings.size());
    int ind_min = distance(ratings.begin(), i_min);
    candies[ind_min]++;
    for (int i = ind_min - 1; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            candies[i] = candies[i + 1] + 1;
        else
            candies[i]++;
    }
    for (int i = ind_min + 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
        else
            candies[i]++;
    }

    int ans = accumulate(candies.begin(), candies.end(), 0);
    return ans;
}

int main()
{
    vector<int> rat = {1, 3, 2, 2, 1};
    // int ans = candy(rat);
    vector<int> ans = allmin(rat);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
}