#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
    int ind = 0;
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] == s[ind])
            ind++;
    }
    return ind == s.length();
}

int main()
{
    string s = "abc", t = "ahbgdc";
    bool ans = isSubsequence(s, t);
    cout << (ans ? "yes" : "no") << endl;
}