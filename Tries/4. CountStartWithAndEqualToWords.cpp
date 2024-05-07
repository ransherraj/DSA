#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* childNode[26];
    int prefixCnt;
    int endCnt;
    
    bool containChar(char ch){
        if(childNode[ch-'A'] != NULL){
            return true;
        }
        return false;
    }
    
    TrieNode* get(char ch){
        return childNode[ch-'A'];
    }
    
    void put(TrieNode* node, char ch){
        childNode[ch-'A'] = node;
    }
    
    void setIncreaseEndCnt(){
        endCnt++;
    }
    
    void setIncreasePrefixCnt(){
        prefixCnt++;
    }
    
    int getEndCnt(){
        return endCnt;
    }
    
    int getPrefixCnt(){
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
        node->setIncreaseEndCnt();
    }
    
    int countWordsEqualTo(string &key){
        TrieNode* node = root;
        for(auto k : key){
            if(node->containChar(k)){
                node = node->get(k);
            }
            else return 0;
        }
        return node->getEndCnt();
    }
    
    int countWordsStartsWith(string &key){
        TrieNode* node = root;
        for(auto k : key){
            if(node->containChar(k)){
                node = node->get(k);
            }
            else return 0;
        }
        return node->getPrefixCnt();
    }
    
    bool searchKey(string &key){
        TrieNode* node = root;
        
        for(auto k : key){
            if(!node->containChar(k)){
                return false;
            }
            node = node->get(k);
        }
        return node->getEndCnt() > 0;
    }
    
    
    void deleteKey(string &key){
        TrieNode* node = root;
        for(char ch : key){
            if(node->containChar(ch)){
                node = node->get(ch);
                node->setDecreasePrefixCnt();
            }
            else {
                return;
            }
        }
        node->setDecreaseEndCnt();
        cout<<key <<" is deleted"<<endl;
    }
};



void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<string> words(n), keys(m), startWithWords(k), equalToWords(k), deleteWords(k);
    
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
    for(int i = 0; i<k; i++){
        cin>>equalToWords[i];
    }
    for(int i = 0; i<k; i++){
        cin>>deleteWords[i];
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
        cout<<"count of words Start with: " <<startWithWords[i]<< " is : " << obj.countWordsStartsWith(startWithWords[i]) <<endl; 
    }
    cout<<"--->...........<---"<<endl;
    for(int i = 0; i<k; i++){
        cout<<"count of words Equal to: " <<equalToWords[i]<< " is : " << obj.countWordsEqualTo(equalToWords[i])<<endl; 
    } 
    cout<<"--->...........<---"<<endl;
    
    for(int i = 0; i<k; i++){
        obj.deleteKey(deleteWords[i]);
    }
    cout<<"--->...........<---"<<endl;
    for(int i = 0; i<k; i++){
        cout<<"count of words Equal to: " <<equalToWords[i]<< " is : " << obj.countWordsEqualTo(equalToWords[i]) <<endl; 
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

1
10 4 4
Ajay Ajay Ankit Aman Raj Ruhan Ruhan Ram Rakesh Suhana
Suhana Ram Ruhan Suatan
Ra Rm Rt S
Ruhan Ram Rak Suhana
ram Ajay Aman Raj



******
Not Working TestCase for Ajay in insert and search with char 'y'
-----
1
10 4 4
Ajay Ajay Ankit Aman Raj Ruhan Ruhan Ram Rakesh Suhana
Suhana Ram Ruhan Ajay
Ra Rm Rt S
Ajay Ram Rak Suhana
Ram Ajay Aman Raj


******



***Working ***

1
10 4 4
Ajar Ajar Ankit Aman Raj Ruhan Ruhan Ram Rakesh Suhana
Suhana Ram Ruhan Ajar
Ra Rm Rt S
Ajar Ram Rak Suhana
Ram Ajay Aman Raj


*** OutPut******

Suhana -> Found
Ram -> Found
Ruhan -> Found
Ajar -> Found
--->...........<---
count of words Start with: Ra is : 3
count of words Start with: Rm is : 0
count of words Start with: Rt is : 0
count of words Start with: S is : 1
--->...........<---
count of words Equal to: Ajar is : 2
count of words Equal to: Ram is : 1
count of words Equal to: Rak is : 0
count of words Equal to: Suhana is : 1
--->...........<---
Ram is deleted
Ajar is deleted
Aman is deleted
Raj is deleted
--->...........<---
count of words Equal to: Ajar is : 1
count of words Equal to: Ram is : 0
count of words Equal to: Rak is : 0
count of words Equal to: Suhana is : 1







*/
