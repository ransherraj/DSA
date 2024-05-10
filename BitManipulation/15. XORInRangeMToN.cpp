/*

Find XOR in range M to N


*****Best Approach****
*Find Pattern
-- How it works---

* Follow previous example
* calculate xorr1 for range 1 to M-1
* calculate xorr2 for range 1 to N
* ans = xorr1 ^ xorr2

*/

#include <bits/stdc++.h>

using namespace std;

int solve2(int N){
    if(N%4 == 1) return 1;
    if(N%4 == 2) return N+1;
    if(N%4 == 3) return 0;
    return N;
}

void solve(){
    int m,n,xorr1 = 0, xorr2 = 0, ans;
    cin >>m>>n;
    xorr1 = solve2(m-1);
    xorr2 = solve2(n);
    ans = xorr1 ^ xorr2;
    cout << "XOR in Range "<<m<<" to " << n << " is " << ans <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
5 9
10 20

Output:
XOR in Range 5 to 9 is 5
XOR in Range 10 to 20 is 21



*/
