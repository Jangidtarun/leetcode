#include <bits/stdc++.h>
using namespace std;

// string makeword(string input, int times)
// {
//     string ans = "";
//     for (int i = 0; i < times; i++)
//         ans += input;
//     return ans;
// }

// string gcdOfStrings(string str1, string str2)
// {
//     int len1 = str1.length(), len2 = str2.length();
//     cout << "before: " << str1 << " " << str2 << endl;
//     if (len1 < len2)
//     {
//         swap(str1, str2);
//         swap(len1, len2);
//     }
//     cout << "after: " << str1 << " " << str2 << endl;
//     int len = min(len1, len2);
//     for (int i = len; i > 0; i--)
//     {
//         string tmp = str2.substr(0, i);
//         if (len1 % i == 0 and len2 % i == 0)
//         {
//             int n1 = len1 / i, n2 = len2 / i;
//             if (str1 == makeword(tmp, n1) and str2 == makeword(tmp, n2))
//                 return tmp;
//         }
//     }
//     return "";
// }

string gcdOfStrings(string str1, string str2)
{
    int len1 = str1.length(), len2 = str2.length();
    if (str1 + str2 != str2 + str1)
        return "";

    int gcdlen = __gcd(len1, len2);
    return str1.substr(0, gcdlen);
}

int main()
{
    string one = "TAUXXTAUXXTAUXXTAUXXTAUXX", two = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    string ans = gcdOfStrings(one, two);
    cout << ans << endl;
}