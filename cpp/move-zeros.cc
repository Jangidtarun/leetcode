#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int a = 0, b = 1;
    while (a < b and b < nums.size())
    {
        if (nums[a] != 0)
            a++, b++;
        if (nums[a] == 0)
        {
            while (nums[b] == 0)
                b++;
            if (b < nums.size())
                swap(nums[a], nums[b]);
            a++, b++;
        }
    }
}

int main()
{
    vector<int> n = {0, 1, 0, 0};
    moveZeroes(n);
    for (int i : n)
        cout << i << " ";
    cout << endl;
}