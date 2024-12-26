#include <bits/stdc++.h>
using namespace std;

void count_edges(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int &ans)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        return;
    if (i - 1 < 0 || grid[i - 1][j] == 0)
        ans++;
    if (i + 1 >= grid.size() || grid[i + 1][j] == 0)
        ans++;
    if (j - 1 < 0 || grid[i][j - 1] == 0)
        ans++;
    if (j + 1 >= grid[0].size() || grid[i][j + 1] == 0)
        ans++;

    vis[i][j] = true;
    if (i - 1 >= 0 and grid[i - 1][j] != 0 and !vis[i - 1][j])
        count_edges(grid, vis, i - 1, j, ans);
    if (i + 1 < grid.size() and grid[i + 1][j] != 0 and !vis[i + 1][j])
        count_edges(grid, vis, i + 1, j, ans);
    if (j - 1 >= 0 and grid[i][j - 1] != 0 and !vis[i][j - 1])
        count_edges(grid, vis, i, j - 1, ans);
    if (j + 1 < grid[0].size() and grid[i][j + 1] != 0 and !vis[i][j + 1])
        count_edges(grid, vis, i, j + 1, ans);

    return;
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int ans = 0;
    vector<vector<int>> vis(grid.size());
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            vis[i].push_back(false);

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (!vis[i][j])
                count_edges(grid, vis, i, j, ans);
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{0,0,1}};

    int ans = islandPerimeter(grid);
    cout << ans << endl;
}