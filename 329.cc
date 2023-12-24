#include <iostream>
#include <vector>
using namespace std;

pair<int, int> _dir_[4] = {{1, 0},
                           {0, 1},
                           {-1, 0},
                           {0, -1}};

void reset(vector<vector<bool>> &v)
{
    for (auto a : v)
        for (auto b : a)
            b = false;
}

bool isaround(int x, int y, int ox, int oy)
{
    return (x == ox and y == oy or
            x == ox - 1 and y == oy or
            x == ox + 1 and y == oy or
            x == ox and y == oy - 1 or
            x == ox and y == oy + 1);
}

class Solution
{
private:
    int dfs(vector<vector<int>> &matrix, int x, int y, int ox, int oy, vector<vector<bool>> &vis, vector<int> &path)
    {
        if (x < 0 or x >= matrix.size() or y < 0 or y >= matrix[0].size())
            return 0;

        // if (isaround(x, y, ox, oy))
        // {
        //     reset(vis);
        //     cout << "reset\n";
        // }

        int ans = 1;
        vis[x][y] = true;
        path.push_back(matrix[x][y]);
        for (auto &[_x, _y] : _dir_)
        {
            int nx = x - _x, ny = y - _y;
            if (nx < 0 or nx >= matrix.size() or ny < 0 or ny >= matrix[0].size())
                continue;

            if (!vis[nx][ny])
                if (matrix[x][y] < matrix[nx][ny])
                    ans = max(ans, 1 + dfs(matrix, nx, ny, ox, oy, vis, path));
        }
        return ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        vector<vector<int>> plen(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                vector<int> path;
                vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(), false));
                plen[i][j] = dfs(matrix, i, j, i, j, vis, path);
                cout << plen[i][j] << "\n";
                for (auto e : path)
                    cout << e << " ";
                cout << "\n";
            }
        }
        int ans = 0;
        for (auto row : plen)
            for (auto el : row)
                ans = max(el, ans);
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{7, 8, 9},
                             {9, 7, 6},
                             {7, 2, 3}};

    int ans = Solution().longestIncreasingPath(v);
    cout << "ans: " << ans << "\n";
}