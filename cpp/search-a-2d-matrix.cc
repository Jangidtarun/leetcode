#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int start = 0;
    int end = m * n - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        int holy = matrix[mid / n][mid % n];
        if (holy < target)
            start = mid + 1;
        else if (holy > target)
            end = mid;
        else
            return true;
    }
    if (matrix[start / n][start % n] == target)
        return true;
    return false;
}

int main()
{
}