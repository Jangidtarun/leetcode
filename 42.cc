#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int totalwater = 0;
    int left = 0, right = n - 1, lmax = INT_MIN, rmax = INT_MIN;
    while (left < right)
    {
        lmax = max(lmax, height[left]);
        rmax = max(rmax, height[right]);
        totalwater += (lmax > rmax) ? rmax - height[right--] : lmax - height[left++];
    }
    return totalwater;
}

int main()
{
    vector<int> v = {4, 2, 0, 3, 2, 5};
    int totalwater = trap(v);
    cout << totalwater << endl;
}