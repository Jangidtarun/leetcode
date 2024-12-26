#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int start = 0, end = 0;
    int tmp = 0;
    int ans = end - start;
    while (start <= end and end < nums.size())
    {
        if (nums[end] == 0)
            tmp++;
        while (tmp > k)
        {
            if (nums[start] == 0)
                tmp--;
            start++;
        }
        end++;
        ans = max(ans, end - start);
    }
    return ans;
}

int main()
{
    vector<int> v = {0, 0, 1, 1, 1, 0, 0};
    //               0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18
    int ans = longestOnes(v, 0);
    cout << ans << endl;
}