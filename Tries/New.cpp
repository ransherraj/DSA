#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* childNode[26];
    int prefixCnt;
    int endCnt;
    
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
    
    void setIncreaseEndCnt(){
        endCnt++;
    }
    
    void setIncreasePrefixCnt(){
        prefixCnt++;
    }
    
    void getEndCnt(){
        return endCnt;
    }
    
    void getPrefixCnt(){
        return prefixCnt;
    }
    
    void setDecreaseEndCnt(){
        endCnt--;
    }
    
    void setDecreasePrefixCnt(){
        prefixCnt--;
    }
    
    
    TrieNode(){
        prefixCnt = 0;
        endCnt = 0;
        for(int i = 0; i<26; i++){
            childNode[i] = NULL;
        }
    }
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
                node->put(new TrieNode(), k);
            }
            node = node->get(k);
            node->setIncreasePrefixCnt();
        }
        node->setEndCnt();
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
    
    bool startWith(string key){
        TrieNode* node = root;
        for(auto k : key){
            if(!node->containChar(k)){
                return false;
            }
            node = node->get(k);
        }
        return true;
    }
};



void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<string> words(n), keys(m), startWithWords(k);
    
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
            cout<<keys[i]<<" -> Found"<<endl;
        }
        else{
            cout<<keys[i]<<"-> Not found"<<endl;
        }
    }
    
    cout<<"--->...........<---"<<endl;
    
    for(int i = 0; i<k; i++){
        if(obj.startWith(startWithWords[i])){
            cout<<"Start with word: " <<startWithWords[i]<<endl;
        }
        else{
            cout<<"Does not start with word: "<<startWithWords[i]<<endl;
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
5 4 4
Raj Ruhan Ram Rakesh Suhana
Suhana Ram Ruhan Suatan
Ra Rm Rt S


Output:

Suhana -> Found
Ram -> Found
Ruhan -> Found
Suatan-> Not found
--->...........<---
Start with word: Ra
Does not start with word: Rm
Does not start with word: Rt
Start with word: S


*/
