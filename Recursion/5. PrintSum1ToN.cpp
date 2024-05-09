
#include <bits/stdc++.h>
using namespace std;

void solve2(int n, int sum){
    
    if(n == 0) {
        cout<<sum;
        return;
    }
    //cout<<n<<endl;
    solve2(n-1, sum + n);
    
}

void solve(){
    int n, sum = 0;
    cin>>n;
    solve2(n, sum);
}

int main(){
    int t; cin>>t; while(t--)solve();
}

