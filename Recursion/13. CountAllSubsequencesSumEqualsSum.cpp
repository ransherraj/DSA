/*

Count all subsequence sum equals sum

*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

int solve3(vector<int> arr, int i, int n, int sum, int tempsum){
    
    if(tempsum == sum) {
        return 1;
    }
    if(tempsum > sum || i >= n ) {
        return 0;
    }
   
    tempsum += arr[i];
    int l = solve3(arr, i+1, n, sum, tempsum);
       
    tempsum -= arr[i];
    int r = solve3(arr, i+1, n, sum, tempsum);
    return l+r;
    
}

void solve(){
    int n, sum, tempsum = 0;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans = solve3(arr, 0, n, sum, tempsum);
    
    cout<<ans<<endl;
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
0
4



*/
