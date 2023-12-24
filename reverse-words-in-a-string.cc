#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string ans = "";
    stringstream words(s);
    vector<string> wordx;
    string word;
    while (words >> word)
        wordx.push_back(word);
    reverse(wordx.begin(), wordx.end());
    for (string tp : wordx)
        ans += tp + " ";

    return ans.substr(0, ans.length() - 1);
}

int main()
{
}