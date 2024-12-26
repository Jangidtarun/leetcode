#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int ans = 0;
    bool flag = false;
    
    while (x > 0)
    {
        if (INT_MAX - ans < x % 10)
        {
            flag = true;
            break;
        }
        ans = ans * 10 + x % 10;
        x /= 10;
    }

    if (flag)
        return 0;
    return ans;
}

int main()
{
    int x = 19843999;
    int ans = reverse(x);
    cout << "ans: " << ans << endl;
}