
/*

*** Combination Sum Leetcode***


*/

#include <bits/stdc++.h>
using namespace std;

void solve2(int i, int n, int sum, vector<int> &arr, vector<int> temp, vector<vector<int>> &ans){
    if(sum == 0 && i == n){
        ans.push_back(temp);
    }
    
    if(i >= n || sum < 0) return;
    
    if(arr[i] <= sum){
        temp.push_back(arr[i]);
        solve2(i, n, sum-arr[i], arr, temp, ans);
        temp.pop_back();
    }
    
    solve2(i+1, n, sum, arr, temp, ans);
    
    
}

void solve(){
    int n , sum;
    cin>>n >> sum;
    vector<int> arr(n), temp;
    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    solve2(0, n, sum, arr, temp, ans);
    
    for(auto x : ans){
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
4 7
2 3 6 7

Output :
2 2 3 
7 



*/
