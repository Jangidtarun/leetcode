#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;
    int first = 0, last = 1;
    vector<int> htable(256);
    htable[s[first]]++;
    int len = 1;

    while (last < s.length())
    {
        int plen = len;
        if (htable[s[last]] < 1)
        {
            htable[s[last]]++;
            last++;
            len++;
        }
        else if (htable[s[last]] == 1)
        {
            htable[s[first]]--;
            first++;
            len--;
        }
        len = max(plen, last - first);
    }
    return len;
}

int main()
{
    string s = "pwwkew";
    int ans = lengthOfLongestSubstring(s);
    cout << "ans: " << ans << endl;
}