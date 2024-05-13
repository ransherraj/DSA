
/*

*********Segment tree***********, 
find sum in certain range of queries
in time complexity less than O(n).


*/

#include <bits/stdc++.h>
using namespace std;

int arr[100005], seg[4*100005];

int query(int ind, int low, int high, int l, int r){
    if(low >= l && high <= r){
        return seg[ind];
    }
    if(l > high || r < low){              // low     l      r    high
        return 0;
    }
    
    int mid = (low + high)/2;
    int left = query(2*ind + 1, low, mid, l, r);
    int right = query(2*ind + 2, mid+1, high, l, r);
    return left+right;
}

void build(int ind, int low, int high){
    
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*ind + 1, low, mid);
    build(2*ind + 2, mid+1, high);
    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}

void solve(){
    int n;
    cin>>n;
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    build(0, 0, n-1);
    
    int q;
    cin>>q;
    int l, r;
    for(int i = 0; i<q; i++){
        cin>>l>>r;
        cout<<query(0, 0, n-1, l, r)<<endl;
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
10
6 4 10 4 2 7 9 2 1 8
3
1 2
1 8
3 8

Output :
14
39
25



*/
