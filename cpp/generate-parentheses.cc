#include <bits/stdc++.h>
using namespace std;

void gen(vector<string> &ans, string &s, int op, int cl)
{
    if (op == 0 and cl == 0)
    {
        ans.push_back(s);
        return;
    }

    if (op > 0)
    {
        s.push_back('(');
        gen(ans, s, op - 1, cl);
        s.pop_back();
    }
    if (cl > op)
    {
        s.push_back(')');
        gen(ans, s, op, cl - 1);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s = "";
    gen(ans, s, n, n);
    return ans;
}

int main()
{
    int n = 3;
    vector<string> par = generateParenthesis(n);
    for (auto val : par)
        cout << val << endl;
}