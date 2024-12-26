#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    vector<vector<int>> merged;
    merged.push_back(points[0]);
    for (int i = 1; i < points.size(); i++)
    {
        if (merged[merged.size() - 1][1] >= points[i][0])
            merged[merged.size() - 1][0] = max(points[i][0], merged[merged.size() - 1][0]), merged[merged.size() - 1][1] = min(points[i][1], merged[merged.size() - 1][1]);
        else
            merged.push_back(points[i]);
    }
    return merged.size();
}