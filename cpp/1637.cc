#include<bits/stdc++.h>
using namespace std;

void printset(set<int> &s){
    for(auto &val: s)
        cout << val << ' ';
    cout << '\n';
}

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> px;
        for(auto &p: points){
            px.insert(p[0]);
        }
        // printset(px);
        int ans = 0;
        vector<int> xc;
        for(auto &val: px){
            xc.push_back(val);
        }
        for(int i=0;i<xc.size()-1;i++){
            ans = max(ans, xc[i+1]-xc[i]);
        }
        
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{8,7},{9,9},{7,4},{9,7}};
    int ans = Solution().maxWidthOfVerticalArea(points);
    cout << "ans: " << ans << '\n';
}