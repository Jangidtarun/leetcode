#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> m(26, 0);
    for (char c : magazine)
        m[c - 'a']++;
    for (char c : ransomNote)
        if (m[c - 'a']-- == 0)
            return false;
    return true;
}

int main()
{
}