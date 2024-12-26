#include <bits/stdc++.h>
using namespace std;

int minSteps(string s, string t)
{
    vector<int> fs(26, 0), ft(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        fs[s[i] - 'a']++;
        ft[t[i] - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (ft[i] < fs[i])
            ans += fs[i] - ft[i];
    }

    return ans;
}

int main()
{
    string s = "bab", t = "aba";
    int ans = minSteps(s, t);
    cout << ans << endl;
}