#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    if (a.length() < b.length())
        return addBinary(b, a);

    int carry = 0;
    int a_index = a.length() - 1;
    int b_index = b.length() - 1;
    string sum(a.length(), '0');
    char tmp = '0';
    while (b_index > -1)
    {
        if (a[a_index] == '1' and b[b_index] == '1')
        {
            tmp = carry + '0';
            sum[a_index] = tmp;
            carry = 1;
        }
        else if (a[a_index] == '0' and b[b_index] == '0')
        {
            tmp = carry + '0';
            sum[a_index] = tmp;
            carry = 0;
        }
        else
        {
            tmp = !carry + '0';
            sum[a_index] = tmp;
        }
        a_index--;
        b_index--;
    }
    while (a_index > -1)
    {
        if (a[a_index] == '1' and carry == 1)
        {
            sum[a_index] = '0';
            carry = 1;
        }
        else
        {
            tmp = carry ^ a[a_index];
            sum[a_index] = tmp;
            carry = 0;
        }
        a_index--;
    }
    if (carry != 0)
        sum.insert(sum.begin(), carry + '0');
    return sum;
}

int main()
{
    string a = "110010";
    string b = "10111";
    cout << addBinary(a, b) << endl;
}