#include<bits/stdc++.h>
using namespace std;

void fun(string s, vector<string> &ans, int n){
    if(n==0) return;
    if(s.length() == n){
        ans.push_back(s);
        return;
    }

    if(s == ""){
        s.push_back('0');
        fun(s,ans,n);
        s.pop_back();
        s.push_back('1');
        fun(s,ans,n);
        s.pop_back();
    }

    int l = s.length()-1;
    if(l >= 0 and s[l] == '0'){
        s.push_back('1');
        fun(s,ans,n);
        s.pop_back();
    }

    l = s.length()-1;
    if(l >= 0 and s[l] == '1'){
        s.push_back('0');
        fun(s,ans,n);
        s.pop_back();
        s.push_back('1');
        fun(s,ans,n);
        s.pop_back();
    }
}

vector<string> validStrings(int n) {
    vector<string> ans;
    string s = "";
    fun(s,ans,n);
    return ans;
}

int main(){

    int n = 3;
    // cin >> n;
    vector<string> ans = validStrings(n);
    for(auto &word: ans)    
        cout << word << ", ";
    cout << endl;

}