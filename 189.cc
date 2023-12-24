#include <bits/stdc++.h>
using namespace std;

// approach1
//  void rotate(vector<int> &nums, int k)
//  {
//      k -= nums.size() * (k / nums.size());
//      int storeans[nums.size()];
//      for (int i = 0; i < nums.size(); i++)
//          storeans[i] = nums[(nums.size() - k + i) % nums.size()];
//      for (int i = 0; i < nums.size(); i++)
//          nums[i] = storeans[i];
//  }

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

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(v, k);
    for (auto val : v)
        cout << val << " ";
    cout << endl;
}