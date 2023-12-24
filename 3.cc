#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int start = 0;
    vector<int> freq(256, -1);
    int ans = 0;
    for (int end = 0; end < s.length(); end++)
    {
        if (freq[s[end]] >= start)
            start = freq[s[end]] + 1;
        freq[s[end]] = end;
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main()
{
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
}