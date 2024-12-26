#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int left = j+1, right = n-1;
            int req_sum = target - (nums[i] + nums[j]);
            while(left < n and right >= 0 and left < right){
                int rem_sum = nums[left] + nums[right];
                if(rem_sum == req_sum){
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    int tmp = nums[left];
                    while(left < n and nums[left] == tmp)
                        left++;
                } else if(rem_sum < req_sum){
                    int tmp = nums[left];
                    while(left < n and nums[left] == tmp)
                        left++;
                } else{
                    int tmp = nums[right];
                    while(right >= 0 and nums[right] == tmp)
                        right--;
                }
            }
            int tmp = nums[j];
            while(j < n and nums[j] == tmp)
                    j++;
            j--;
        }
        int tmp = nums[i];
        while(i < n and nums[i] == tmp)
            i++;
        i--;
    }
    return ans;
}
    
int main(){
    vector<int> nums = {0,1,-1,10,2,-1,0,5,0,0};
    vector<vector<int>> ans = fourSum(nums, 2);
    for(auto &v: ans){
        for(auto &elm: v){
            cout << elm << " ";
        }
        cout << endl;
    }
}
