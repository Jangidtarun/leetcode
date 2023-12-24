#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        int num = 0;
        string tmp = "";
        if (s[i] != ']')
        {
            st.push(s[i]);
            continue;
        }

        if (s[i] == ']')
        {
            while (st.top() != '[')
                tmp = st.top() + tmp, st.pop();
            st.pop();

            string tmpnum;
            while (!st.empty() and !isalpha(st.top()) and st.top() != '[')
                tmpnum = st.top() + tmpnum, st.pop();

            for (char c : tmpnum)
                num = num * 10 + c - '0';
        }

        while (num--)
            for (char c : tmp)
                st.push(c);
    }

    int num = 0;
    if (!st.empty() and !isalpha(st.top()))
        num = num * 10 + st.top() - '0', st.pop();

    string tmp = "";
    while (num--)
        for (char c : tmp)
            st.push(c);

    string ans = "";
    while (!st.empty())
        ans = st.top() + ans, st.pop();

    return tmp + ans;
}

int main()
{
    string c = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    // string c = "3[z]2[2[t]]";
    string ans = decodeString(c);
    cout << ans << endl;
}