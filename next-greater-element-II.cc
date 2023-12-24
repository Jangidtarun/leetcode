#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> nge(n);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        while (!st.empty() and nums[st.top() % n] < nums[i % n])
        {
            nge[st.top() % n] = nums[i % n];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        if (st.top() < n)
            nge[st.top()] = -1;
        st.pop();
    }

    return nge;
}

int main()
{

    vector<int> nums1 = {1, 2, 1};
    vector<int> ans = nextGreaterElement(nums1);
    for (auto val : ans)
        cout << val << endl;
}