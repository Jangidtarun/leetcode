#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int minlen = strs[0].length();
    for (int i = 0; i < strs.size(); i++)
        minlen = min((int)strs[i].length(), minlen);
    string ans = "";
    for (int j = 0; j < minlen; j++)
    {
        char tmp = strs[0][j];
        ans += tmp;
        bool flag = true;
        for (int i = 1; i < strs.size(); i++)
            if (strs[i][j] != tmp)
            {
                ans.pop_back();
                return ans;
            }
    }
    return ans;
}

int main()
{
    vector<string> v = {"flower", "flow", "flight"};
    string ans = longestCommonPrefix(v);
    cout << ans << endl;
}