#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;

    unordered_map<string, vector<string>> m;
    for (string &s : strs)
    {
        string tmpword = s;
        sort(tmpword.begin(), tmpword.end());
        m[tmpword].push_back(s);
    }

    for (auto [s, v] : m)
        ans.push_back(v);
    return ans;
}

int main()
{
    vector<string> v = {"a"};
    vector<vector<string>> ans = groupAnagrams(v);

    for (auto vi : ans)
    {
        for (auto s : vi)
            cout << s << " ";
        cout << '\n';
    }
}