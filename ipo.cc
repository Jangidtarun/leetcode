#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    set<pair<int, int>> s;
    for (int i = 0; i < profits.size(); i++)
        s.insert({capital[i], profits[i]});

    sort(s.begin(), s.end());
    
}

int main()
{
}