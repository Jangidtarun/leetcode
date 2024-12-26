#include <bits/stdc++.h>
using namespace std;

string convert(string s, int n)
{
    if (n == 1)
        return s;
    string ans;
    int i = 0;
    while (ans.length() < s.length())
    {
        int id[2] = {2 * n - 2 - 2 * i, 0 + 2 * i};
        int index = i;
        while (index < s.length())
        {
            for (int v : id)
            {
                if (v > 0 and index < s.length())
                {
                    ans += s[index];
                    index += v;
                }
            }
        }
        i++;
    }
    return ans;
}

int main()
{
    string inp = "paypalishiring";
    int nrow = 3;
    string ans = convert(inp, nrow);
    cout << ans.length() << " " << ans << endl;
}