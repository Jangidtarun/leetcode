#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int closest_sum = INT_MAX/10;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n-2;i++){
        int first = i+1, second = n-1;
        while(first < second){
            int curr_sum = nums[first] + nums[second] + nums[i];
            if(abs(curr_sum-target) < abs(closest_sum-target))
                closest_sum = curr_sum;
            if(curr_sum > target) second--;
            else if(curr_sum < target) first++;
            else return target;
        }
    }
    return closest_sum;
}

int main(){
    vector<int> v = {0,3,97,102,200};
    int target = 300;
    int ans = threeSumClosest(v,target);
    cout << ans << endl;
}