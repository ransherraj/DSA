/*

Remove Rightmost bit in a number

a = a & (a-1);

---How it works---

          R 
1)  16 -> 1 0 0 0 0
    15 -> 0 1 1 1 1
    ----------------
& =       0 0 0 0 0
    ----------------
    
              R
2)  40 -> 1 0 1 0 0 0
    39 -> 1 0 0 1 1 1
    -----------------
& =       1 0 0 0 0 0
    -----------------
    

              R
3)  84 -> 1 0 1 0 1 0 0
    83 -> 1 0 1 0 0 1 1
    --------------------
& =       1 0 1 0 0 0 0
    --------------------
    


Binary Number ->   1    1    0    0     1
          Bit ->  4th  3rd  2nd  1st   0th Bit

*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a;
    cin>>a;
    
    int ans = a & (a-1);
    
    cout<<ans<<endl;
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
0
32
80


*/
