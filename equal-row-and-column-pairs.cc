#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>> &grid)
{
    int n = grid.size();
    string row[n], col[n];
    for (int i = 0; i < n; i++)
        row[i] = "", col[i] = "";

    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            row[i] += to_string(grid[i][j]) + 'a', col[i] += to_string(grid[j][i]) + 'a';


    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (row[i] == col[j])
                ans++;

    return ans;
}

int main()
{
    vector<vector<int>> grid = {{11, 1}, {1, 11}};
    int ans = equalPairs(grid);
    cout << ans << endl;
}