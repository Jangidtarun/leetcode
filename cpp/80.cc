#include <bits/stdc++.h>
using namespace std;

/*
int removeDuplicates(vector<int> &nums)
{
    if (nums.size())
        return nums.size();
    int counter = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] == nums[i - 1])
            counter++;
        else
            counter = 0;
        if (counter > 2)
            nums.erase(nums.begin() + i);
    }
    return nums.size();
}
*/

// arr = {1,1,1,2,2,3}
//        0,1,2,3,4,5

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    if(n < 3) return n;
    int first = 0;
    int counter = 1;
    for(int i=0;i<n;i++){
        if(first == 0 or first == 1 or nums[first-2] != nums[i])
            nums[first++] = nums[i];
    }
    return first;
}

int main()
{
    vector<int> nums = {1,2,3};
    int ans = removeDuplicates(nums);
    cout << ans << endl;
    for (auto val : nums)
        cout << val << " ";
    cout << endl;
}