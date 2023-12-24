#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if (t.length() == 0)
        return "";
    if (s.length() < t.length())
        return "";
    unordered_map<char, int> tcounter, window;
    for (char tchar : t)
        tcounter[tchar]++;

    int left = 0, have = 0, need = tcounter.size();
    int head = 0, d = INT_MAX;
    for (int right = 0; right < s.length(); right++)
    {
        window[s[right]]++;
        if (tcounter.find(s[right]) != tcounter.end() and tcounter[s[right]] == window[s[right]])
            have++;

        while (have == need)
        {
            if (right - left + 1 < d)
            {
                d = right - left + 1;
                head = left;
            }
            window[s[left]]--;
            if (tcounter.find(s[left]) != tcounter.end() and tcounter[s[left]] > window[s[left]])
                have--;
            left++;
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    string ans = minWindow(s, t);
    cout << ans << endl;
}