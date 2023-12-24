#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else
        return false;
}

string reverseVowels(string s)
{
    vector<int> loco;
    for (int i = 0; i < s.length(); i++)
        if (is_vowel(s[i]))
            loco.push_back(i);

    for (int i = 0; 2 * i + 1 <= loco.size(); i++)
        swap(s[loco[i]], s[loco[loco.size() - (i + 1)]]);
    return s;
}

int main()
{
    string s = "tari";
    string ans = reverseVowels(s);
    cout << ans << endl;
}
