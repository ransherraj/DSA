/*

Number of bits need to flip to make a number a equals b

=> count all set bits of xor of a and b.

Binary Number ->   1    1    0    0     1
          Bit ->  4th  3rd  2nd  1st   0th Bit

*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int ans = a ^ b;
    int cnt = 0;
    
    while(ans != 0){
        ans = ans & (ans-1);
        cnt++;
    }
    
    cout<<"Number of bits need to flip to make a number a equals b : "<<cnt<<endl;
    
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
3
3 4
2 3
30 40

Output:
Number of bits need to flip to make a number a equals b : 3
Number of bits need to flip to make a number a equals b : 1
Number of bits need to flip to make a number a equals b : 4


*/
