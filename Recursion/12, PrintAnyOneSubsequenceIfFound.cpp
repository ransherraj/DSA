/*

Print any one subsequence equals sum if found

*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

bool solve3(vector<int> arr, int i, int n, int sum, int tempsum, vector<int> &temp){
    
    if(tempsum == sum) {
        return true;
    }
    if(tempsum > sum || i >= n ) {
        return false;
    }
    
    temp.push_back(arr[i]);
    tempsum += arr[i];
    return solve3(arr, i+1, n, sum, tempsum, temp);
        
    temp.pop_back();
    tempsum -= arr[i];
    return solve3(arr, i+1, n, sum, tempsum, temp);
    
    
}

void solve(){
    int n, sum, tempsum = 0;
    cin>>n>>sum;
    vector<int> arr(n), temp;
    vector<vector<int>> ans;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    bool found = solve3(arr, 0, n, sum, tempsum, temp);
    //cout<<found<<endl;
    if(found){
        for(auto x : temp){
            cout<<x<<" ";
        }
    }
    else{
        cout<<"Not Found";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
6 60
1 2 3 4 5 6
6 6
1 2 3 4 5 6

Output:
Not Found
1 2 3 



*/
