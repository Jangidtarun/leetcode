#include <bits/stdc++.h>
using namespace std;

// will require Dynamic programming
// not complete yet. :p

int rob(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
        sum += max(nums[i], nums[i + 1]);
    return sum;
}

int main()
{
    vector<int> v = {2, 1, 1, 2};
    int ans = rob(v);
    cout << ans << endl;
}