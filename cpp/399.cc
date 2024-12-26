#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> vis;
unordered_map<string, vector<pair<string, double>>> graph;
void dfs(string source, unordered_map<string, double> m)
{
    if (vis[source])
        return;
    vis[source] = true;
    for (auto &[child_str, wt] : graph[source])
    {
        m[child_str] = m[source] * wt;
    }
}

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries)
{
    unordered_set<string> vars;
    for (int i = 0; i < equations.size(); i++)
    {
        vars.insert(equations[i][0]);
        vars.insert(equations[i][1]);
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }
    for (auto s : vars)
        dijkstra(s);

    vector<double> ans;
    for (auto vec : queries)
    {
        pair<string, string> q = {vec[0], vec[1]};
        if (vars.find(q.first) == vars.end() or vars.find(q.second) == vars.end())
            ans.push_back(-1);
        else
            ans.push_back(m[q]);
    }
    return ans;
}