#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int ans = 0;
    int pans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            ans = 0;
        else
            pans = ++ans;
    }
    return pans;
}

int main()
{
    string s = "   fly me   to   the moon  ";
    int ans = lengthOfLastWord(s);
    cout << ans << endl;
}