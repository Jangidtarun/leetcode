#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{
    sort(citations.rbegin(), citations.rend());
    // for (auto val : citations)
    //     cout << val << " ";
    cout << endl;
    int h = 0;
    while (h < citations.size() and citations[h] >= h)
        h++;
    return h;
}

int main()
{
    vector<int> v = {0, 1};
    //               0, 1, 2, 3, 4
    int ans = hIndex(v);
    cout << ans << endl;
}