#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
    if (s.length() > t.length())
        return false;
    if (s.length() == t.length() and s != t)
        return false;
    if (s.length() == t.length() and s == t)
        return true;
    int spointer = 0, tpointer = 0;
    while (spointer < s.length() and tpointer < t.length())
    {
        if (s[spointer] == t[tpointer])
            spointer++;
        tpointer++;
    }
    return spointer == s.length() - 1;
}