#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, char> m, m2;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.find(s[i]) != m.end() and m[s[i]] != t[i])
            return false;
        if (m2.find(t[i]) != m2.end() and m2[t[i]] != s[i])
            return false;
        m[s[i]] = t[i];
        m2[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s = "12";
    string t = "\u0067\u0068";
    bool ans = isIsomorphic(s, t);
    cout << (ans ? "yes" : "no") << endl;
}