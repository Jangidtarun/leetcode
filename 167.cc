#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
            return {left+1, right+1};
        if (numbers[left] + numbers[right] > target)
            right--;
        else if (numbers[left] + numbers[right] < target)
            left++;
    }
    // if (numbers[left] + numbers[right] == target)
    //     return {left, right};
    return {left+1, right+1};
}