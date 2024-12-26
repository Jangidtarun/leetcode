#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    stringstream ss(s);
    string word;
    unordered_map<string, char> visited;
    string string_pattern = "";
    char start_char = 'a';
    while (ss >> word)
    {
        if (visited.find(word) != visited.end())
            string_pattern.push_back(visited[word]);
        else
        {
            visited[word] = start_char;
            string_pattern.push_back(visited[word]);
            start_char++;
        }
    }

    // cout << "string pattern: " << string_pattern << endl;

    string patter_int = "";
    unordered_map<char, int> _s_pa_;
    int tmp_deno = 0;
    for (int i = 0; i < pattern.length(); i++)
    {
        if (_s_pa_.find(pattern[i]) == _s_pa_.end())
        {
            _s_pa_[pattern[i]] = tmp_deno;
            tmp_deno++;
        }
        patter_int.push_back((_s_pa_[pattern[i]] + '0'));
    }
    cout << "pattern_int: " << patter_int << endl;
    string string_pattern_int = "";
    _s_pa_.clear();
    tmp_deno = 0;
    for (int i = 0; i < string_pattern.length(); i++)
    {
        if (_s_pa_.find(string_pattern[i]) == _s_pa_.end())
        {
            _s_pa_[string_pattern[i]] = tmp_deno;
            tmp_deno++;
        }
        string_pattern_int.push_back((_s_pa_[string_pattern[i]] + '0'));
    }
    cout << "string_pattern_int: " << patter_int << endl;

    if (patter_int == string_pattern_int)
        return true;
    return false;
}

int main()
{
    string pattern = "abba", s = "dog cat cat dog";
    bool out = wordPattern(pattern, s);
    if (out)
        cout << "true\n";
    else
        cout << "false\n";
}