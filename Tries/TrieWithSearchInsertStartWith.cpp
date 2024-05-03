#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* childNode[26];
    int preCont;
    int endCount;
    bool wordEnd = false;
    
    bool containChar(char ch){
        return childNode[ch-'a'] != NULL;
    }
    
    TrieNode* get(char ch){
        return childNode[ch-'a'];
    }
    
    void put(TrieNode* node, char ch){
        childNode[ch-'a'] = node;
    }
    
    bool setWordend(){
        return wordEnd = true;
    }
    
    bool getWordend(){
        return wordEnd;
    }
    
    // TrieNode(){
    //     wordEnd = false;
    //     for(int i = 0; i<26; i++){
    //         childNode[i] = NULL;
    //     }
    // }
};

class Trie{
    private: TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    
    void insertKey(string &key){
        TrieNode* node = root;
        
        for(auto k : key){
            if(!node->containChar(k)){
                //cout<<"not contain ::::"<<k<<endl;
                cout<<"cc :"<<key <<" : "<<node->getWordend()<<endl;
                node->put(new TrieNode(), k);
            }
            node->get(k);
        }
        
        node->setWordend();
    }
    
    bool searchKey(string &key){
        TrieNode* node = root;
        for(auto k : key){
            if(!node->containChar(k)){
                return false;
            }
            node = node->get(k);
        }
        return node->getWordend() == true;
    }
    
    // bool startWith(string key){
    //     TrieNode* node = root;
    //     for(auto k : key){
    //         if(!node->containChar(k)){
    //             return false;
    //         }
    //         node = node->get(k);
    //     }
    //     return true;
    // }
    
    
};



void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<string> words(n), keys(m), startWithWords(k);
    //TrieNode* root = new TrieNode();
    
    Trie obj;
    
    for(int i = 0; i<n; i++){
        cin>>words[i];
    }
    for(int i = 0; i<m; i++){
        cin>>keys[i];
    }
    for(int i = 0; i<k; i++){
        cin>>startWithWords[i];
    }
    
    for(int i = 0; i<n; i++){
        obj.insertKey(words[i]);
    }
    
    for(int i = 0; i<m; i++){
        if(obj.searchKey(keys[i])){
            cout<<keys[i]<<" found"<<endl;
        }
        else{
            cout<<keys[i]<<" not found"<<endl;
        }
    }
    
    // for(int i = 0; i<k; i++){
    //     if(obj.startWith(startWithWords[i])){
    //         cout<<"Start with word :" <<startWithWords[i]<<endl;
    //     }
    //     else{
    //         cout<<"Does not start with word :" <<startWithWords[i]<<endl;
    //     }
    // } 
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



1
5 4 4
Sanju Suman Sarita Sakhshi Sukanya
Suman Sita Samir Sukanya
Sum Sur Sar Sat


Output:

Ramu not found
Ram found
Raju not found
Rashi not found




*/
