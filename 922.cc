#include <bits/stdc++.h>
using namespace std;

bool botheven(int a, int b) { return !(a % 2) and !(b % 2); }
bool bothodd(int a, int b) { return (a % 2) and (b % 2); }

vector<int> sortArrayByParityII(vector<int> &nums)
{
    int first = 0, second = nums.size() - 1;
    while (first < second)
    {
        while (first < second and botheven(nums[first], first) or bothodd(nums[first], first))
            first++;
        while (first < second and botheven(nums[second], second) or bothodd(nums[second], second))
            second--;
        swap(nums[first], nums[second]);
    }
    return nums;
}

int main()
{
    vector<int> v = {4, 2, 5, 7};
    vector<int> ans = sortArrayByParityII(v);
    for (auto val : ans)
        cout << val << " ";
    cout << "\n";
    // cout << (botheven(4, 0) ? "yes" : "no") << "\n";
}