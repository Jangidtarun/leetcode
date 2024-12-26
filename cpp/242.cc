#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int maps[26] = {0};
    int mapt[26] = {0};
    for (char c : s)
        maps[c - 'a']++;
    for (char c : t)
        mapt[c - 'a']++;
    for (int i = 0; i < 26; i++)
        if (maps[i] != mapt[i])
            return false;
    return true;
}

int main()
{
    unordered_map<char, int> m = {
        {'a', 3},
        {'r', 1},
        {'9', 2}};
    for (auto &[f, s] : m)
        cout << f << ", " << s << '\n';
}