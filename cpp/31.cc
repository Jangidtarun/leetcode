#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
  int n = nums.size();
  int second = n - 1, first = second - 1;
  while (first >= 0 and first < second)
  {
    while (first >= 0 and nums[first] >= nums[second])
    {
      first--;
      second--;
    }
    {
      if (first < 0)
        reverse(nums.begin(), nums.end());
      else
      {
        int x = first + 1;
        for (int i = first + 1; i < n; i++)
        {
          if (nums[i] > nums[first] and nums[i] <= nums[x])
          {
            x = i;
          }
        }
        swap(nums[first], nums[x]);
        reverse(nums.begin() + first + 1, nums.end());
      }
      break;
    }
  }
}

int main()
{
  vector<int> arr = {2, 1};
  nextPermutation(arr);
  for (auto &el : arr)
    cout << el << " ";
  cout << endl;
}