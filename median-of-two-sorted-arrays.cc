#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int pt1 = 0, pt2 = 0;
    vector<int> md;
    while (pt1 < nums1.size() and pt2 < nums2.size())
    {
        if (nums1[pt1] < nums2[pt2])
        {
            md.push_back(nums1[pt1]);
            pt1++;
        }
        else
        {
            md.push_back(nums2[pt2]);
            pt2++;
        }
    }

    while (pt1 < nums1.size())
    {
        md.push_back(nums1[pt1]);
        pt1++;
    }
    while (pt2 < nums2.size())
    {
        md.push_back(nums2[pt2]);
        pt2++;
    }

    int n = md.size();
    double med = n % 2 ? md[n / 2] : (md[n / 2 - 1] + md[n / 2]) / 2.0;
    return med;
}

int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {2};
    double med = findMedianSortedArrays(nums1, nums2);
    cout << med << endl;
}