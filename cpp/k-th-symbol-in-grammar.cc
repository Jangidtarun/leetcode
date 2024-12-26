#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k)
{
    if (n == 1)
        return 0;
    if (k % 2)
        return (kthGrammar(n - 1, (k + 1) / 2) == 0) ? 0 : 1;
    return (kthGrammar(n - 1, k / 2) == 0) ? 1 : 0;
}

int main()
{
    int n = 2, k = 3;
    int ans = kthGrammar(n, k);
    cout << "ans: " << ans << endl;
}