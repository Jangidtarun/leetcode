#include <bits/stdc++.h>
using namespace std;

// approach1
 void rotate(vector<int> &nums, int k)
 {
     int n = nums.size();
     k -= n * (k / n);
     int storeans[n];
     for (int i = 0; i < n; i++)
         storeans[i] = nums[(n - k + i) % n];
     for (int i = 0; i < n; i++)
         nums[i] = storeans[i];
 }

// approach2
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k -= n * (k / n);
    for (int i = 0; i < (n - k); i++)
        nums.push_back(nums[i]);
    for (int i = 0; i < (n - k); i++)
        nums.erase(nums.begin());
}

// approach3
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(v, k);
    for (auto val : v)
        cout << val << " ";
    cout << endl;
}