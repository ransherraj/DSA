/*

Factorial

TC : O(N)
SC : O(N)


*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>

using namespace std;

int solve3(int n){
    if(n == 0) return 1;
    return n * solve3(n-1);
}

void solve(){
    int n;
    cin>>n;
    int ans = solve3(n);
    cout<<"Factorial is "<<ans<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
5
6

Output:
Factorial is 120
Factorial is 720




*/
