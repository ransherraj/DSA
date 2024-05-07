/*

Problem statement
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).


*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* childNode[26];
    bool containChar(char ch){
        if(childNode[ch-'a'] != NULL){
            return true;
        }
        return false;
    }
    
    TrieNode* get(char ch){
        return childNode[ch-'a'];
    }
    
    void put(TrieNode* node, char ch){
        childNode[ch-'a'] = node;
    }
};


void solve(){
    TrieNode * root = new TrieNode();
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0; i<s.size(); i++){
        TrieNode* node = root;
        for(int j = i; j<s.size(); j++){
            if(!node->containChar(s[j])){
                ans++;
                node->put(new TrieNode(), s[j]);
            }
            node = node->get(s[j]);
        }
    }
    cout<<"Number of substrings for : "<< s << " is "<<ans+1<<endl;
}

int main() { 
    int t; 
    cin>>t;
    while(t--) {
        solve();
    }
	return 0;
}


/* 

Input :
2
sds
abc

Output :
Number of substrings for : sds is 6
Number of substrings for : abc is 7


*/
