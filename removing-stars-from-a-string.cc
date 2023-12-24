#include <bits/stdc++.h>
using namespace std;

string removeStars(string s)
{
    string ans = "";
    for (char c : s)
        if (c == '*')
            ans.pop_back();
        else
            ans += c;
    return ans;
}

int main()
{
    string s = "leet**cod*e";
    string ans = removeStars(s);
    cout << ans << endl;
}