
#include <bits/stdc++.h>
using namespace std;

void solve2(int n){
    
    if(n == 0) return;
    
    solve2(n-1);
    cout<<n<<endl;
}

void solve(){
    int n;
    cin>>n;
    solve2(n);
}

int main(){
    int t; cin>>t; while(t--)solve();
}

