#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    vector<int> hmaps(26);
    vector<int> hmapt(26);
    for (int i = 0; i < s.length(); i++)
        hmaps[s[i] - 'a']++;
    for (int i = 0; i < t.length(); i++)
        hmapt[t[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        hmaps[i] = abs(hmaps[i] - hmapt[i]);
    int nop = accumulate(hmaps.begin(), hmaps.end(), 0);
    if (nop != 0)
        return false;
    return true;
}

int main()
{
    string s = "rat", t = "cat";
    bool out = isAnagram(s, t);
    if (out)
        cout << "true\n";
    else
        cout << "false\n";
}