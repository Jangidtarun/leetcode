#include <bits/stdc++.h>
using namespace std;

int nextnumber(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = nextnumber(n);
    while (fast != 1 and fast != slow)
    {
        slow = nextnumber(slow);
        fast = nextnumber(nextnumber(fast));
    }
    return fast == 1;
}

int main()
{
    int ans = isHappy(7);
    cout << (ans ? "happy" : "no") << '\n';
}