#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;
    int freq1[26] = {0}, freq2[26] = {0};

    for (char c : word1)
        freq1[c - 'a']++;
    for (char c : word2)
        freq2[c - 'a']++;

    for (int i = 0; i < 26; i++)
        if (freq1[i] == 0 and freq2[i] == 0)
            continue;
        else if (!(freq1[i] > 0 and freq2[i] > 0))
            return false;

    sort(freq1, freq1 + 26);
    sort(freq2, freq2 + 26);
    for (int i = 0; i < 26; i++)
        if (freq1[i] != freq2[i])
            return false;
    return true;
}

int main()
{
    string word1 = "uau", word2 = "ssx";
    bool ans = closeStrings(word1, word2);
    cout << (ans ? "yes" : "no") << endl;
}