#include <bits/stdc++.h>
using namespace std;

vector<int> findIndices(vector<int> &nums, int id, int vd)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <= i - id; j++)
            if (vd <= abs(nums[i] - nums[j]))
                return {i, j};
        for (int j = i + id; j < nums.size(); j++)
            if (vd <= abs(nums[i] - nums[j]))
                return {i, j};
    }
    return {-1, -1};
}

int main()
{
    vector<int> x = {5, 1, 4, 1};
    int id = 2, vd = 4;
    vector<int> s = findIndices(x, id, vd);
    for (auto v : s)
        cout << v << " ";
    cout << "\n";
}