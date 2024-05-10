/*

Find XOR in range 1 to N

****Naive Apprach****
For loop and find XOR----> TC : O(N) Not good


*****Best Approach****
*Find Pattern
-- How it works---

N=1                1     
N=2      1^2       3   
N=3     1^2^3      0
N=4    1^2^3^4     4

N=5    1^2...^5    1
N=6    1^2...^6    7
N=7    1^2...^7    0
N=8    1^2...^5    8

N=9    1^2...^9    1

Pattern :::
N%4 == 1           1
N%4 == 2          N+1
N%4 == 3           0
N%4 == 0           N

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
    int n,xorr = 0;
    cin >> n;
    xorr = solve2(n);
    cout << "XOR in Range 1 To " << n << " is " << xorr <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
8
9

Output:
XOR in Range 1 To 8 is 8
XOR in Range 1 To 9 is 1



*/
