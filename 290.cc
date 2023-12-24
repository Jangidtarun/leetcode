#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    vector<string> v;
    stringstream ss(s);
    string word;
    while (ss >> word)
        v.push_back(word);

    if (v.size() != pattern.length())
        return false;

    for (int i = 0; i < pattern.length(); i++)
    {
        if (m1.find(pattern[i]) != m1.end() and m1[pattern[i]] != v[i])
            return false;
        if (m2.find(v[i]) != m2.end() and m2[v[i]] != pattern[i])
            return false;
        m1[pattern[i]] = v[i];
        m2[v[i]] = pattern[i];
    }
    return true;
}