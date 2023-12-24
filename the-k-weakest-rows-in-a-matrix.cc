#include <bits/stdc++.h>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> weakest;
    for (int i = 0; i < mat.size(); i++)
    {
        auto it = upper_bound(mat[i].rbegin(), mat[i].rend(), 0);
        // cout << mat[i].rend() - it << endl;
        weakest.push_back({mat[i].rend() - it, i});
    }

    auto cmp = [](pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    };

    sort(weakest.begin(), weakest.end(), cmp);
    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.push_back(weakest[i].second);
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    int k = 3;
    vector<int> ans = kWeakestRows(mat, k);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
}