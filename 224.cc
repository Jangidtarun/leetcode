#include <bits/stdc++.h>
using namespace std;

int solveexpression(vector<string> expression)
{
    stack<string> s;
    for (auto tmpstr : expression)
    {
        if (s.empty())
            s.push(tmpstr);
        else
        {
            if (s.top() == "-")
            {
                s.pop();
                int num1 = 0;
                if (!s.empty())
                {
                    num1 = stoi(s.top());
                    s.pop();
                }
                int num2 = stoi(tmpstr);
                int res = num1 - num2;
                s.push(to_string(res));
            }
            else if (s.top() == "+")
            {
                s.pop();
                int num1 = stoi(s.top());
                s.pop();
                int num2 = stoi(tmpstr);
                int res = num1 + num2;
                s.push(to_string(res));
            }
            else
                s.push(tmpstr);
        }
    }
    return stoi(s.top());
}

int calculate(string s)
{
    stack<string> t;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (t.empty())
        {
            string tmp = "";
            while (i < s.length() and isalnum(s[i]))
                tmp += s[i], i++;
            if (tmp != "")
            {
                i--;
                t.push(tmp);
                continue;
            }
            else
                tmp += s[i];
            t.push(tmp);
        }
        else
        {
            if (s[i] == ')')
            {
                // cout << "detected a closing bracket\n";
                vector<string> tmp;
                while (!t.empty() and t.top() != "(")
                {
                    tmp.push_back(t.top());
                    t.pop();
                }
                t.pop();
                reverse(tmp.begin(), tmp.end());
                int res = solveexpression(tmp);
                t.push(to_string(res));
            }
            else
            {
                string tmp = "";
                while (i < s.length() and isalnum(s[i]))
                    tmp += s[i], i++;
                if (tmp != "")
                {
                    i--;
                    t.push(tmp);
                    continue;
                }
                else
                    tmp += s[i];
                t.push(tmp);
            }
        }
    }

    vector<string> tmp;
    while (!t.empty())
    {
        tmp.push_back(t.top());
        t.pop();
    }
    reverse(tmp.begin(), tmp.end());
    int res = solveexpression(tmp);
    t.push(to_string(res));

    return stoi(t.top());
}

int main()
{
    string ex = "(1+(4+5+2)-3)+(6+8)";
    // vector<string> ed = {"-", "3", "+", "2"};
    // int res = solveexpression(ed);
    // cout << res << "\n";
    int ans = calculate(ex);
    cout << "ans: " << ans << '\n';
}