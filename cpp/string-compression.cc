#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    char prev = chars[0];
    int len = 1;
    for (unsigned int i = 1; i <= chars.size(); i++)
    {
        if (i < chars.size() and chars[i] == prev)
            len++;
        else
        {
            auto start = chars.begin() + i - len + 1, end = chars.begin() + i;
            chars.erase(start, end);
            int numofdig = 0;
            int storelen = len;
            if (len > 1)
                while (len > 0)
                {
                    int tmp = len % 10;
                    chars.insert(start, tmp + '0');
                    len /= 10;
                    numofdig++;
                }
            i = i - (storelen - 1) + numofdig;
            if (i < chars.size())
                prev = chars[i];
            len = 1;
        }
    }
    return chars.size();
}

int main()
{
    vector<char> v = {'b'};
    int ans = compress(v);
    for (char c : v)
        cout << c << " ";
    cout << endl;
    cout << ans << endl;
}