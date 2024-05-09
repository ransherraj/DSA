#include <bits/stdc++.h>
/*

Binary Number ->   1    1    0    0     1
          Bit ->  4th  3rd  2nd  1st   0th Bit

*/


using namespace std;

void solve(){
    int a,n;
    cin>>a>>n;
    bool isSet1 = a & (1<<n);
    bool isSet2 = (a>>n) & 1;
    string ans1 = isSet1 ? "set." : "not set.";
    string ans2 = isSet2 ? "set." : "not set.";
    cout<<"For number "<<a<<", "<<n<<"th bit is "<<ans1<<endl;
    cout<<"For number "<<a<<", "<<n<<"th bit is "<<ans2<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
1
25 4

Output:
For number 25, 5th bit is set.
For number 25, 5th bit is set.

*/
