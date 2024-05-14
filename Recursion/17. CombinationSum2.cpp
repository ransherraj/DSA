
/*

*** Combination Sum II Leetcode***
*each element should used once


*/

#include <bits/stdc++.h>
using namespace std;

void solve2(int i, int n, int sum, vector<int> &arr, vector<int> temp, set<vector<int>> &ans){
    if(sum == 0 && i == n){
        ans.insert(temp);
    }
    
    if(i > n || sum < 0) return;
    
    if(arr[i] <= sum){
        temp.push_back(arr[i]);
        solve2(i+1, n, sum-arr[i], arr, temp, ans);
        temp.pop_back();
    }
    
    solve2(i+1, n, sum, arr, temp, ans);
    
    
}

void solve(){
    int n , sum;
    cin>>n >> sum;
    vector<int> arr(n), temp;
    set<vector<int>> ans;
    vector<vector<int>> res;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    solve2(0, n, sum, arr, temp, ans);
    
    for(auto x : ans){
        vector<int>tempp;
        for(auto y : x){
            tempp.push_back(y);
        }
        res.push_back(tempp);
    }
    
    for(auto x : res){
        for(auto y : x){
            cout<< y <<" ";
        }
        cout<<endl;
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
7 8
10 1 2 7 6 1 5

Output :
1 1 6 
1 2 5 
1 7 
2 6 



*/
