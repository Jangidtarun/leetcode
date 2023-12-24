#include <bits/stdc++.h>
using namespace std;

int main()
{
    int purchaseAmount = 11;
    int roundedamount;
    if (purchaseAmount % 10 == 0 or purchaseAmount % 10 < 5)
        roundedamount = 10 * (purchaseAmount / 10);
    else
        roundedamount = 10 * (purchaseAmount / 10 + 1);
    cout << 100 - roundedamount << endl;
}