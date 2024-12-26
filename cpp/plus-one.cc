#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int index = digits.size() - 1;
    vector<int> ans(index + 1, 0);
    for (int i = 0; i <= index; i++)
        ans[i] = digits[i];
    if (digits[index] + 1 < 10)
        ans[index] = digits[index] + 1;

    else
    {
        int carry = 1;
        while (index > -1)
        {
            carry = digits[index] + carry;
            ans[index] = carry % 10;
            if (carry < 10)
            {
                carry = 0;
                break;
            }
            carry /= 10;
            index--;
        }
        if (carry != 0)
            ans.insert(ans.begin(), carry);
    }
    return ans;
}

int main()
{
    vector<int> hari = {9, 9};
    vector<int> shiv = plusOne(hari);
    for (auto rudra : shiv)
        cout << rudra;
    cout << endl;
}