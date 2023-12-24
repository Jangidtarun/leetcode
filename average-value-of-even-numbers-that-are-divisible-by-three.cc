#include <bits/stdc++.h>
using namespace std;

int averageValue(vector<int> &nums)
{
    long long sum = 0;
    int count = 0;
    for (int n : nums)
    {
        if (!(n % 6))
        {
            sum += n;
            count++;
        }
    }
    int avg = 0;
    if (count != 0)
        avg = sum / count;
    return avg;
}

int main()
{
    vector<int> arr = {1, 3, 6, 10, 12, 15};
    int ans = averageValue(arr);
    cout << ans << endl;
}