/*

Power Set : Using bit manipulation
// Print all subsets

TC : N * 2^N
SC : ~ N * 2^N

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve2 (vector<int> arr){
    vector<vector<int>> ans;
    int n = arr.size();
    int subsets = 1 << n;
    //cout<<subsets<<endl;
    
    for(int i = 0; i<subsets ; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1) {
                temp.push_back(arr[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<vector<int>>ans;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    ans = solve2(arr);
    
    for(auto x : ans){
        cout<<"[";
        for(auto y : x){
            cout<< y <<",";
        }
        cout<<"]"<<endl;
    }
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
1
3
1 2 3

Output:
[]
[1,]
[2,]
[1,2,]
[3,]
[1,3,]
[2,3,]
[1,2,3,]



*/
