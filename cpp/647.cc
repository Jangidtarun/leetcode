#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int recfun(int start, int end)
{
    int ans = 0;
    if (start == end)
        return true;
}

int countSubstrings(string s)
{
    bool tmp = recfun(0, s.length() - 1);
    return ans;
}

int main()
{
    string s = "aaa";
    int ans = countSubstrings(s);
    cout << "ans: " << ans << endl;
}