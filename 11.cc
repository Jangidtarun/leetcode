#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int water = 0;
    while (left < right)
    {
        water = max(water, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return water;
}

int main()
{
    vector<int> h = {1, 2, 3, 4, 5, 25, 24, 3, 4};
    //               0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    int ans = maxArea(h);
    cout << ans << endl;
}