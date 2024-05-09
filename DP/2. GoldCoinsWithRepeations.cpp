#include <bits/stdc++.h>

using namespace std;


int solve(int n, vector<int> &v, int w){
    
    if(w == 0) return 1;
    
    if(n <= 0 || w < 0) return 0;
    
    
    return solve(n-1, v, w) + solve(n, v, w-v[n-1]);
}
int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];
    int w;
    cin>>w;
    
    cout<<solve(n, v, w)<<endl;
    return 0;
}
