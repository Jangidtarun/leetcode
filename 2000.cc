#include<bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
    int index = 0;
    for(int i=0;i<word.length();i++){
        if(word[i] == ch){
            index = i;
            break;
        }
    }
    reverse(word.begin(), word.begin() + 1 + index);
    return word;
}

int main(){
    string word = "abcd";
    string newword = reversePrefix(word, 'b');
    cout << newword << endl;
}