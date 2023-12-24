#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;
bool uniqueOccurrences(vector<int> &arr)
{
    int pfreq[N] = {0};
    for (int val : arr)
        pfreq[val + 1000]++;

    bool visit[N] = {false};
    for (int val : pfreq)
    {
        if (val != 0 and visit[val] == true)
            return false;
        visit[val] = true;
    }
    return true;
}

int main()
{
    bool val[100] = {false};
    for (int i = 0; i < 100; i++)
        cout << val[i] << " ";
    cout << endl;
}