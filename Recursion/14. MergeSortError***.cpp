/*

****** Merge Sort *****
* split array low to mid in one part and mid+1 to high in other
* Merge the array recurcively

*/

#include <bits/stdc++.h>
using namespace std;

void merge(int start, int end, int mid, vector<int> &arr){
    vector<int> temp(end - start + 1);
    
    int i = start;
    int j = mid + 1;
    int k = 0;
    
    while( i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    
    for(int i = 0; i<temp.size(); i++){
        arr[start + i] = temp[i];
    }
}

void mSort(int start, int end, vector<int> &arr){
    if(start >= end) return;
    
    int mid = (start + end) / 2;
    mSort(start, mid, arr);
    mSort(mid+1, end, arr);
    merge(start, end, mid, arr);
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    mSort(0, n-1, arr);
    
    cout<<"Sorted Array"<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
10
6 4 10 4 2 7 9 2 1 8

Output :
Sorted Array
1 2 2 4 4 6 7 8 9 10 



*/
