#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans;
    for (int i = 0; i < 13; i++)
        while (num >= values[i])
            ans += romans[i],
                num -= values[i];
    return ans;
}

int main()
{
    int num = 2834;
    cout << intToRoman(num) << endl;
}