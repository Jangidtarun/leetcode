#include <bits/stdc++.h>
using namespace std;

// direction coordinates
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int row, int col)
{
    vis[row][col] = true;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i], ncol = col + dy[i];
        if (nrow >= 0 and ncol >= 0 and nrow < heights.size() and ncol < heights[0].size() and !vis[nrow][ncol] and heights[nrow][ncol] >= heights[row][col])
            dfs(heights, vis, nrow, ncol);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    vector<vector<int>> coords;
    for (int row = 0; row < m; row++)
    {
        // attack from left column
        dfs(heights, pacific, row, 0);
        // attack from right column
        dfs(heights, atlantic, row, n - 1);
    }
    for (int col = 0; col < n; col++)
    {
        // attack from top row
        dfs(heights, pacific, 0, col);
        // attack from bottom row
        dfs(heights, atlantic, m - 1, col);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (pacific[i][j] == atlantic[i][j] and pacific[i][j])
                coords.push_back({i, j});
    return coords;
}

int main()
{
}