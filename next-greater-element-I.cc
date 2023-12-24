#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> num1;
    stack<int> ng;
    unordered_map<int, int> nge;
    for (auto val : nums1)
    {
        num1.insert(val);
        nge[val];
    }

    for (auto val : nums2)
    {
        while (!ng.empty() and ng.top() < val)
        {
            nge[ng.top()] = val;
            ng.pop();
        }
        if (num1.find(val) != num1.end())
        {
            ng.push(val);
        }
    }

    while (!ng.empty())
    {
        nge[ng.top()] = -1;
        ng.pop();
    }

    vector<int> vada;
    for (auto val : nums1)
        vada.push_back(nge[val]);
    return vada;
}

int main()
{

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (auto val : ans)
    {
        cout << val << endl;
    }
}