#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int ans = 0;
    map<int,int> m;
    for(auto val: nums){
        m[val]++;
    }
    for(auto val: m){
        if(val.second > nums.size()/2){
            ans = val.first;
        }
    }
    return ans;
}

int main() {}