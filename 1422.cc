#include<bits/stdc++.h>
using namespace std;

void printvec(vector<int> &v){
    for(auto &val: v)
        cout << val << ' ';
    cout << '\n';
}

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zeros(n-1), ones(n-1);
        
        zeros[0] = s[0]=='0';
        for(int i=1;i<n-1;i++){
            if(s[i]=='0') zeros[i] = zeros[i-1]+1;
            else zeros[i] = zeros[i-1];
        }
        // printvec(zeros);

        ones[n-2] = s[n-1]=='1';
        for(int i=n-3;i>=0;i--){
            if(s[i+1] == '1'){
                ones[i] = ones[i+1] + 1;
            } else{
                ones[i] = ones[i+1];
            }
        }
        // printvec(ones);

        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max(ans, ones[i] + zeros[i]);
        }
        return ans;
    }
};

int main(){
    string input = "011101";
    int ans = Solution().maxScore(input);
    cout << "ans: " << ans << '\n';
}