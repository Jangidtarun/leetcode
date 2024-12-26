#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    if (n == 0 or n == 1)
        return 0;
    int count = 0;
    vector<int> is_prime(n, true);
    is_prime[1] = false;
    for (int i = 1; i < n; i++)
    {
        if (is_prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
                is_prime[j] = false;
        }
    }
    return count;
}

int main()
{
}