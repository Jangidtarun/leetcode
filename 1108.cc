#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string s)
{
    string ans;
    string delimiter = ".";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
        ans += token + "[.]";
    }
    ans += token;
    return ans;
}

int main()
{
    string s = "255.100.50.0";
    cout << defangIPaddr(s) << "\n";

    vector<int> x(10,3);
    for(auto val: x) cout << val;
}