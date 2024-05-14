
/*

*** Subset Sum I Leetcode***


*/

#include <bits/stdc++.h>
using namespace std;

void solve2(int i, int n, int sum, vector<int> &arr, vector<int> &ans){
    
    if(i == n) ans.push_back(sum);
    
    if(i >= n ) return;
    
    
    sum += arr[i];
    solve2(i+1, n, sum, arr, ans);
    sum -= arr[i];
    solve2(i+1, n, sum, arr, ans);
    
    
}

void solve(){
    int n ;
    cin>>n;
    vector<int> arr(n), ans;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    solve2(0, n, 0, arr, ans);
    
    for(auto x : ans){
        cout<< x <<" ";
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
3
3 1 2


Output :
6 4 5 3 3 1 2 0 


*/
