/*

Merge Sort

*****Best Approach****
* split array low to mid in one part and mid+1 to high in other
* Merge the array recurcively

*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    cout<<low << " "<<mid<< " " << high <<"*"<<endl;
    vector<int>temp;
    int left = low;
    int right = mid+1;
    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left <= mid){
        temp.push_back(arr[left]);
    }
    while(right <= high){
        temp.push_back(arr[right]);
    }
    
    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

void solve3(vector<int> &arr, int low, int high){
    
    
    if(low == high) return;
    int mid = (low + high)/2;
    
    solve3(arr, low, mid);
    solve3(arr, mid+1, high);
    cout<<low << " "<<mid<< " " << high<<endl;
    merge(arr, low, mid, high);
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    //cout<<n<<endl;
    solve3(arr, 0, n-1);
    
    for(auto x : arr){
        cout<<x<<" ";
    }
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
5
1 2 4 3 1

Output:
Error

*/
