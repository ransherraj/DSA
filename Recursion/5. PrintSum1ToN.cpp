
#include <bits/stdc++.h>
using namespace std;


// Parameterised way , every time value is added to sum in parameter.

/******** Parameterised way *****/
void solve2(int n, int sum){
    
    if(n == 0) {
        cout<<sum;
        return;
    }
    //cout<<n<<endl;
    solve2(n-1, sum + n);
    
}

// Functional Way, 
int solve3(int n){
    
    if(n == 0) {
        return 0;
    }
    return n + solve3(n-1);
}

void solve(){
    int n, sum = 0;
    cin>>n;
    solve2(n, sum);
}

int main(){
    int t; cin>>t; while(t--)solve();
}

