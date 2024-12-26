#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int max_height = 0;
    int peak = 0;
    for (int h : gain)
        max_height = max(max_height, peak += h);
    return max_height;
}

int main()
{
    vector<int> v = {-4, -3, -2, -1, 4, 3, 2};
    int ans = largestAltitude(v);
    cout << ans << endl;
}