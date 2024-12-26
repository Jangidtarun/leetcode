#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int start = 0, end = matrix[i].size() - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (matrix[i][mid] == target)
                return true;
            if (matrix[i][mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        if (matrix[i][start] == target)
            return true;
    }
    return false;
}

bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int m = 0;
    int n = matrix[m].size() - 1;
    while (m < matrix.size() and n < matrix[0].size())
    {
        if (matrix[m][n] == target)
            return true;
        if (matrix[m][n] > target)
            n--;
        else
            m++;
    }
    if (m < matrix.size() and n < matrix[0].size() and matrix[m][n] == target)
        return true;
    return false;
}

int main()
{
    vector<vector<int>> v = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 5;
    bool ans = searchMatrix(v, target);
    cout << ans ? "true\n" : "false\n";
}