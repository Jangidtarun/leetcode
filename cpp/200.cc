#include <bits/stdc++.h>
using namespace std;

pair<int, int> _dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<vector<char>> &g, int x, int y)
{
    if (x < 0 or x >= g.size() or y < 0 or y >= g[0].size() or g[x][y] == '0')
        return;
    g[x][y] = '0';
    for (auto dir : _dir)
    {
        pair<int, int> newdir = {x + dir.first, y + dir.second};
        dfs(g, newdir.first, newdir.second);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int ans = 0;
    for (int row = 0; row < grid.size(); row++)
        for (int col = 0; col < grid[0].size(); col++)
            if (grid[row][col] == '1')
            {
                dfs(grid, row, col);
                ans++;
            }
    return ans;
}

int main()
{
    vector<vector<char>> g =
        {{'1', '1', '0', '0', '0'},
         {'1', '1', '0', '0', '0'},
         {'0', '0', '1', '0', '0'},
         {'0', '0', '0', '1', '1'}};

    int ans = numIslands(g);
    cout << ans << "\n";
}