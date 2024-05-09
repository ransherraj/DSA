
#include <bits/stdc++.h>
using namespace std;

void solve2(string s, int n){
    
    if(n == 0) return;
    cout<<s<<endl;
    solve2(s, n-1);
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    solve2(s, n);
}

int main(){
    int t; cin>>t; while(t--)solve();
}

