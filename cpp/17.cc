#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<char,string> m = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void fun(vector<string> &ans, string s, const string &d, int i){
    if(i == d.length()){
        ans.push_back(s);
        return;
    }

    for(char &c: m[d[i]]){
        s.push_back(c);
        fun(ans, s,d,i+1);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    vector<string> ans;
    string s = "";
    fun(ans, s, digits, 0);
    return ans;
}


int main(){
    string digits = "937";
    vector<string> ans = letterCombinations(digits);
    for(auto &comb: ans)
        cout << comb << endl;
}