#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate)
{
    queue<int> rad, dir;
    int n = senate.size();
    for (int i = 0; i < n; i++)
        if (senate[i] == 'R')
            rad.push(i);
        else
            dir.push(i);

    while (!rad.empty() and !dir.empty())
    {
        if (rad.front() > dir.front())
            dir.push(n++);
        else
            rad.push(n++);
        rad.pop(), dir.pop();
    }

    return rad.empty() ? "Dire" : "Radiant";
}

int main() {}