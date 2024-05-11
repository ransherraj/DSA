/*

Print all subsets equal sum

*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

void solve3(vector<int> arr, int i, int n, int sum, int tempsum, vector<int> &temp, vector<vector<int>> &ans){
    if(tempsum == sum) {
        ans.push_back(temp);
        return;
    }
    if(tempsum > sum || i >= n) {
        return;
    }
    temp.push_back(arr[i]);
    tempsum += arr[i];
    solve3(arr, i+1, n, sum, tempsum, temp, ans);
    temp.pop_back();
    tempsum -= arr[i];
    solve3(arr, i+1, n, sum, tempsum, temp, ans);
    
}

void solve(){
    int n, sum, tempsum = 0;
    cin>>n>>sum;
    //cout<<n<<" "<<sum<<endl;
    vector<int> arr(n), temp;
    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    solve3(arr, 0, n, sum, tempsum, temp, ans);
    
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
6 6
1 2 3 4 5 6

Output:
[ 1 2 3 ]
[ 1 5 ]
[ 2 4 ]
[ 6 ]


*/
