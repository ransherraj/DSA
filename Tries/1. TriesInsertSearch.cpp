/*  
The Trie data structure is a tree-like data structure used for storing a dynamic set of strings. It is commonly used for efficient retrieval and storage of keys in a large dataset. 
Time Complexity: O(number of words * maxLengthOfWord)
Auxiliary Space: O(number of words * maxLengthOfWord)

Operation	Time       Complexity	     Auxiliary Space
Insertion	           O(n)	           O(n*m)
Searching          	 O(n)	           O(1)

Implementation of Insert and Search Operations in Trie Data Structure:
Steps-by-step approach:

Create a root node with the help of TrieNode() constructor.
Store a collection of strings that have to be inserted in the trie in a vector of strings say, arr.
Inserting all strings in Trie with the help of the insert_key() function,
Search strings with the help of search_key() function.

*/


#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* childNode[26];
    bool wordEnd;
    TrieNode(){
        wordEnd = false;
        for(int i = 0; i<26; i++){
            childNode[i] = NULL;
        }
    }
};

void insertKey(TrieNode* root, string &key){
    TrieNode* node = root;
    
    for(auto k : key){
        if(node->childNode[k - 'a'] == NULL){
            TrieNode* newNode = new TrieNode();
            node->childNode[k - 'a'] = newNode;
        }
        node = node->childNode[k - 'a'];
    }
    node->wordEnd = true;
}

bool searchKey(TrieNode* root, string &key){
    TrieNode* node = root;
    for(auto k : key){
        if(node->childNode[k - 'a'] == NULL){
            return false;
            break;
        }
        node = node->childNode[k - 'a'];
    }
    return node->wordEnd == true;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> words(n), keys(m);
    TrieNode* root = new TrieNode();
    for(int i = 0; i<n; i++){
        cin>>words[i];
    }
    for(int i = 0; i<m; i++){
        cin>>keys[i];
    }
    
    for(int i = 0; i<n; i++){
        insertKey(root, words[i]);
    }
    
    for(int i = 0; i<m; i++){
        if(searchKey(root, keys[i])){
            cout<<keys[i]<<" found"<<endl;
        }
        else{
            cout<<keys[i]<<" not found"<<endl;
        }
    } 
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

1
5 4
Raj Raman Ram Rakesh Ramesh
Ramu Ram Raju Rashi

Output:

Ramu not found
Ram found
Raju not found
Rashi not found

*/
