#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix_xor(n,0);
    prefix_xor[0] = arr[0];

    for(int i=1;i<n;i++){
        prefix_xor[i] = prefix_xor[i-1]^arr[i];
    }

    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int val = 0;
            if(i==0)
                val = prefix_xor[j];
            else
                val = prefix_xor[j] ^ prefix_xor[i-1];
            if(!val){
                ans += j-i;
                cout << "subarray: [" << i << "," << j << "] total: " << j-i << endl;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,1,1,1,1};
    // vector<int> arr = {2,3,1,6,7};
    int ans = countTriplets(arr);
    cout << "ans: " << ans << endl;
}