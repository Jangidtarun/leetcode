#include <bits/stdc++.h>
using namespace std;

bool checkRecord(string s)
{
    int begin = 0;
    int end = 0;
    int absent_count = 0;
    bool eligible = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
            absent_count++;
        begin = i;
        end = begin;
        while (s[end] == 'L' and end < s.length())
        {
            end++;
        }
        if (end - begin >= 3 or absent_count >= 2)
            eligible = false;
        if (end - begin > 0)
            i += end - begin - 1;
    }
    return eligible;
}

int main()
{
    string lgb = "PPALLP";
    bool ans = checkRecord(lgb);
    cout << "eligible? " << ans << endl;
}