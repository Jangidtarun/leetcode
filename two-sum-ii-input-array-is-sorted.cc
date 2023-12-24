#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int start = 0, end = numbers.size() - 1;
    while (numbers[start] + numbers[end] != target)
        if (numbers[start] + numbers[end] > target)
            end--;
        else
            start++;

    return {start + 1, end + 1};
}

int main()
{
    vector<int> v = {3, 24, 50, 79, 88, 150, 345};
    int t = 200;
    vector<int> ans = twoSum(v, t);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
}