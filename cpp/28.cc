#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int ans = -1;
    if (haystack.find(needle) != haystack.npos)
        ans = haystack.find(needle);
    return ans;
}

int main()
{
    string needle = "ood", haystack = "sadooddloode";
    int pos = strStr(haystack, needle);
    cout << "ans: " << pos << endl;
}