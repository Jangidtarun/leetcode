#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string tmp = "";
    for (char c : s)
        if (isalnum(c))
            tmp += tolower(c);
    string revs = tmp;
    reverse(revs.begin(), revs.end());
    return tmp == revs;
}

int main()
{
    string s = "&^%W%^^WHOCLCI*U#Bo8oi76rftF(na;ksdvap";
    bool ans = isPalindrome(s);
}