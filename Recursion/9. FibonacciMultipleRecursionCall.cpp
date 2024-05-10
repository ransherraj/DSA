/*

Multiple Recursion Calls

Example:
1) Fibonacci
2) N-Queen
and more.....

**** Fibonacci Using Reursion ****


*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

int solve3(int n){
    if(n <= 1) return n;
    return solve3(n-1) + solve3(n-2);
}

void solve(){
    int n;
    cin>>n;
    int fib = solve3(n);
    cout<<fib<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
3
3
5
8

Output:
2
5
21

*/
