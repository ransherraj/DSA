/*

Print all subsequences

* subsequence : a contiguous or non-contiguous sequence which follow ORDER....
* Subarray can also be Subsequence
* empty set is also Subsequence

Arr : [ 3, 1, 2]

Subsequence :

contiguous Subsequence :  [3]
contiguous Subsequence :  [1]
contiguous Subsequence :  [2]
contiguous Subsequence :  [3, 1]
contiguous Subsequence :  [1, 2]
non-contiguous Subsequence :  [3, 2]
contiguous Subsequence :  [3, 1, 2]

Non-subsequences :
[3, 2, 1]
[1, 3]
[2, 1]
Becouse it does not follows order


*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

void solve3(vector<int>arr, int i, int n, vector<int> &temp, vector<vector<int>> &ans){
    if(i == n) {
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(arr[i]);
    solve3(arr, i+1, n, temp, ans);
    temp.pop_back();
    solve3(arr, i+1, n, temp, ans);
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n), temp;
    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    solve3(arr, 0, n, temp, ans);
    
    for(auto x : ans){
        cout<<"["<<" ";
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<"]"<<endl;
    }
    
    cout<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
1
3
3 1 2

Output:
[ 3 1 2 ]
[ 3 1 ]
[ 3 2 ]
[ 3 ]
[ 1 2 ]
[ 1 ]
[ 2 ]
[ ]







*/
