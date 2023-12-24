#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int psum = 0;
    for (int i = 0; i < k; i++)
        psum += nums[i];
    int sum = psum;
    for (int i = k; i < nums.size(); i++)
    {
        psum += nums[i] - nums[i - k];
        sum = max(sum, psum);
    }
    return (double)sum / k;
}

int main()
{
    vector<int> num = {1, 12, -5, -6, 50, 3};
    double ans = findMaxAverage(num, 4);
    cout << "val: " << ans << endl;
}