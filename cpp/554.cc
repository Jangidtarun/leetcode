#include <bits/stdc++.h>
using namespace std;

int leastBricks(vector<vector<int>> &wall)
{
    int n = wall.size();
    unordered_map<int, int> edge_map;

    for (int i = 0; i < n; i++)
    {
        int edge_position = wall[i][0];
        edge_map[edge_position]++;
        for (int j = 1; j < wall[i].size() - 1; j++)
        {
            edge_position += wall[i][j];
            edge_map[edge_position]++;
        }
    }

    int max_edge_count = 0;
    for (auto &[_, freq] : edge_map)
        max_edge_count = max(max_edge_count, freq);

    return n - max_edge_count;
}

int main()
{
    vector<vector<int>> wall = {{1, 2, 2, 1},
                                {3, 1, 2},
                                {1, 3, 2},
                                {2, 4},
                                {3, 1, 2},
                                {1, 3, 1, 1}};

    int ans = leastBricks(wall);
    cout << ans << endl;
}