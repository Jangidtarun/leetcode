#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k)
{
    int n = s.length();
    int count = 0;
    int maxunique = 0;
    vector<int> hmap_visited(26);
    for (int i = 0; i < n; i++)
    {
        if (hmap_visited[s[i] - 'a'] == 0)
        {
            maxunique++;
            hmap_visited[s[i] - 'a']++;
        }
    }
    for (int i = 1; i <= maxunique; i++)
    {
        vector<int> hmap_f(26);
        int wstart = 0, wend = 0, unique = 0, countleastk = 0;
        while (wend < n)
        {
            if (unique <= i)
            {
                if (!hmap_f[s[wend] - 'a'])
                    unique++;
                hmap_f[s[wend] - 'a']++;
                if (hmap_f[s[wend] - 'a'] == k)
                    countleastk++;
                wend++;
            }

            else
            {
                if (hmap_f[s[wstart] - 'a'] == k)
                    countleastk--;
                hmap_f[s[wstart] - 'a']--;
                if (!hmap_f[s[wstart] - 'a'])
                    unique--;
                wstart++;
            }
            if (unique == countleastk and unique == i)
                count = max(wend - wstart, count);
        }
    }
    return count;
}

int main()
{
    string s = "aaabbb";
    int k = 3;
    int ans = longestSubstring(s, k);
    cout << ans << endl;
}