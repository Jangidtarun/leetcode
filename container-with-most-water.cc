#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int start = 0, end = height.size() - 1;
    int max_vol = 0;
    while (start <= end)
    {
        int tmp_vol = min(height[start], height[end]) * (end - start);
        if (tmp_vol > max_vol)
            max_vol = tmp_vol;
        if (height[start] <= height[end])
            start++;
        else if (height[start] > height[end])
            end--;
    }
    return max_vol;
}

int main()
{
}