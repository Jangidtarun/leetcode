#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    int start = 1, end = x / 2;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (mid > x / mid)
            end = mid;
        else if (mid < x / mid)
            start = mid + 1;
        else
            return mid;
    }

    if (start > x / start)
        return start - 1;
    return start;
}

int main()
{
	int query;
	cout << "enter a number: ";
	cin >> query;
	int res = mySqrt(query);
    cout << "sqrt("<< query << "): " << res << endl;
    cout << "added credential feature\n";
}
