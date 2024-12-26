#include <bits/stdc++.h>
using namespace std;

int minPartitions(string s)
{
    int ans = s[0] - '0';
    for (auto ch : s)
        ans = max(ans, ch - '0');
    return ans;
}

int main()
{
}