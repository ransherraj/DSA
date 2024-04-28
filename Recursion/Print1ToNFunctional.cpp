
#include <bits/stdc++.h>
using namespace std;

int solve2(int n){
    
    if(n == 0) {
        return 0;
    }
    return n + solve2(n-1);
    
}

void solve(){
    int n, sum = 0;
    cin>>n;
    int ans = solve2(n);
    cout<<ans;
}

int main(){
    int t; cin>>t; while(t--)solve();
}

