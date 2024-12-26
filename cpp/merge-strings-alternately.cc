#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string s = "";
    int i = 0;
    for (; i < word1.length() and i < word2.length(); i++)
    {
        s.push_back(word1[i]);
        s.push_back(word2[i]);
    }
    int tmp = i;
    for (; i < word1.length(); i++)
        s.push_back(word1[i]);
    for (; tmp < word2.length(); tmp++)
        s.push_back(word2[tmp]);

    return s;
}

int main()
{
    string w1 = "word", w2 = "wordword";
    string ans = mergeAlternately(w1, w2);
    cout << ans << endl;
}