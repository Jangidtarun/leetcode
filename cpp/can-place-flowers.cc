#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int len = flowerbed.size();
    for (int i = 0; i < len; i++)
        if (flowerbed[i] == 0)
            if (!flowerbed[max(0, i - 1)] and !flowerbed[min(len - 1, i + 1)])
            {
                flowerbed[i] = 1;
                n--;
            }
    return n <= 0;
}

int main()
{
    vector<int> fl = {0, 1, 0, 1, 0, 1, 0, 0};
    int n = 1;
    bool ans = canPlaceFlowers(fl, n);
    cout << (ans ? "true" : "false") << endl;
}