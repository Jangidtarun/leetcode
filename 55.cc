#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int maxreach = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > maxreach)
            return false;
        maxreach = i + nums[i];
    }
    return true;
}

int main()
{
    vector<int> v = {2, 3, 1, 1, 4};
    bool ans = canJump(v);
    cout << (ans ? "yes" : "no") << endl;
}