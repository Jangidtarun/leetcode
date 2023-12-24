#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    stringstream ss(s);
    vector<string> words;
    string w;
    while (ss >> w)
        words.push_back(w);
    reverse(words.begin(), words.end());
    string ans = "";
    for (auto word : words)
    {
        ans += word + " ";
    }
    ans.pop_back();
    return ans;
}

int main()
{
}