#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> onesrow(m), onescol(n), zerosrow(m), zeroscol(n);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) onesrow[i]++;
                else zerosrow[i]++;
            }
        }

        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j] == 1) onescol[j]++;
                else zeroscol[j]++;
            }
        }

        vector<vector<int>> diff(m, vector<int>(n,0));   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j] = onesrow[i] + onescol[j] - zeroscol[j] - zerosrow[i];
            }
        }

        return diff;
    }
};

int main(){

}