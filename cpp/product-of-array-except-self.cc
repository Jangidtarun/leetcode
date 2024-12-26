#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int len = nums.size();
    int prefix[len];
    int suffix[len];
    prefix[0] = 1;
    suffix[len - 1] = 1;
    for (int i = 1; i < len; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
        suffix[len - 1 - i] = suffix[len - i] * nums[len - i];
    }

    vector<int> ans(len);
    for (int i = 0; i < len; i++)
        ans[i] = prefix[i] * suffix[i];
    return ans;
}

int main()
{
    vector<int> tati = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(tati);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
}