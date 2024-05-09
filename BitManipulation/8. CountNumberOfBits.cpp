/*

Count Number of set bits


******* Since Bitwise operators are faster than other operators, they are prefered in CP *******

Odd Check : 
if( n & 1) => 'odd' else 'even'

Divide by 2 : 
n/2 = n>>1

Example : In binary search we should use (low + high) >> 1

Divide by 2 to power k : 
n/(2^k) = n>>k

Multiply by 2:
n*2 = n<<1

Multiply by 2 to power k:
n*(2*k) = n<<k

******* Since Bitwise operators are faster than other operators, they are prefered in CP *******

Binary Number ->   1    1    0    0     1
          Bit ->  4th  3rd  2nd  1st   0th Bit

*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a;
    cin>>a;
    int cnt = 0;
    
    while(a > 0){
        cnt += a & 1;  // replacing cnt += a%2
        a = a >> 1;     // replacing a = a / 2
    }
    
    cout<<"Number of set bits : "<<cnt<<endl;
    
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
Number of set bits : 1
Number of set bits : 2
Number of set bits : 3



*/
