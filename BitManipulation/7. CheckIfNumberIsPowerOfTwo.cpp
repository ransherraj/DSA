/*

Check if number is power of 2

if (a & (a-1)) == 0  => power of 2;

---How it works---

Every number with power of 2 has only one set bit.
Eg : 8 -> 1000
    16 -> 10000


Binary Number ->   1    1    0    0     1
          Bit ->  4th  3rd  2nd  1st   0th Bit

*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a;
    cin>>a;
    
    int ans = a & (a-1);
    
    if(ans == 0) cout<<a<<" is power of 2"<<endl;
    else cout<<a<<" is not power of 2"<<endl;
    
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
3
16
40
84

Output:
16 is power of 2
40 is not power of 2
84 is not power of 2



*/
