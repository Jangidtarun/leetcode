#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> ans;
    unordered_map<string, int> hash;
    for (string w : words)
        hash[w]++;

    int lenofeachword = words[0].length();
    int lenofpermuation = lenofeachword * words.size();
    for (int i = 0; i + lenofpermuation <= s.length(); i++)
    {
        unordered_map<string, int> tmp = hash;
        int count = 0;
        for (int j = i; j < s.length(); j += lenofeachword)
        {
            string tmpstr = s.substr(j, lenofeachword);
            if (tmp[tmpstr] > 0)
            {
                tmp[tmpstr]--;
                count++;
            }
            else
                break;
        }
        if (count == words.size())
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<string> v = {"word", "good", "best", "good"};
    string s = "wordgoodgoodgoodbestword";
    vector<int> ans = findSubstring(s, v);
    for (auto val : ans)
        cout << val << " ";
    cout << endl;
}