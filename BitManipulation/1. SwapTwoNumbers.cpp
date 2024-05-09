#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b;
    cin>>a>>b;
    a = a^b;
    b = a^b; // = (a^b)^b = a
    a = a^b; // = (a^b)^a = b
    cout<<a<<" "<<b<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
1
10 15

Output:
15 10

*/
