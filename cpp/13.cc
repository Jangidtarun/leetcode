#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> num = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (num[s[i]] < num[s[i + 1]])
            ans -= num[s[i]];
        else
            ans += num[s[i]];
    }
    ans += num[s.back()];
    return ans;
}

int main()
{
    string numeral = "DCXXI";
    int ans = romanToInt(numeral);
    cout << ans << endl;
}