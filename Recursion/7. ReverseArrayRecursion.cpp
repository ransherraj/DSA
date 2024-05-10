/*

Reverse Array using Recursion


*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

void solve3(vector<int>&arr, int i, int n){
    int temp = arr[i];
    if(i >= n/2) return;
    
    int c = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = c;
    
    solve3(arr, i+1, n);
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    solve3(arr, 0, n);
    for(auto X : arr) {
        cout<<X<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
6
1 3 4 5 6 6
5
1 3 4 5 6

Output:
6 6 5 4 3 1 
6 5 4 3 1 





*/
