#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int maxVowels(string s, int k)
{
    int maxvowels = 0;
    for (int i = 0; i < k; i++)
    {
        if (is_vowel(s[i]))
            maxvowels++;
    }
    int ans = maxvowels;
    for (int i = k; i < s.length(); i++)
    {
        if (is_vowel(s[i]))
            maxvowels++;
        if (is_vowel(s[i - k]))
            maxvowels--;
        ans = max(ans, maxvowels);
    }
    return ans;
}

int main()
{
    string s = "aeke";
    int ans = maxVowels(s, 3);
    cout << ans << endl;
}