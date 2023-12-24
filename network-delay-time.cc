#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;

int networkDelayTime(vector<vector<int>> &times, int n, int start)
{
    vector<pair<int, int>> graph[n + 1];
    for (auto entry : times)
        graph[entry[0]].push_back({entry[1], entry[2]});

    vector<bool> vis(n + 1, false);
    vector<int> level(n + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    level[start] = 0;
    q.push({start, level[start]});

    while (!q.empty())
    {
        auto cv = q.top();
        q.pop();
        vis[cv.first] = true;
        for (auto child : graph[cv.first])
        {
            int clevel = level[child.first];
            int nlevel = level[cv.first] + child.second;
            if (clevel > nlevel)
            {
                level[child.first] = nlevel;
                q.push({child.first, level[child.first]});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (level[i] == INF)
            return -1;
        ans = max(ans, level[i]);
    }
    return ans;
}

int main()
{
}