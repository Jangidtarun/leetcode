#include<bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
    string tmp;
    bool flag_found = false;
    for(char &c: word){
        tmp.push_back(c);
        if(c == ch){
            flag_found = true;
            break;
        }
    }
    if(!flag_found) return word;
    
    cout << "tmp: " << tmp << endl;
    reverse(tmp.begin(), tmp.end());
    for(int i=0;i< tmp.length();i++){
        word[i] = tmp[i];
    }
    return word;
}

int main(){
    string word = "abcd";
    string newword = reversePrefix(word, 'z');
    cout << newword << endl;
}