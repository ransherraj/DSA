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
    string ans1 = isSet1 ? "set." : "not set.";
    cout<<"Initial : For number "<<a<<", "<<n<<"th bit is "<<ans1<<endl;
    
    a = a | (1<<n);
    
    isSet1 = a & (1<<n);
    ans1 = isSet1 ? "set." : "not set.";
    cout<<"After Set : For number "<<a<<", "<<n<<"th bit is "<<ans1<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
1
25 5

Output:
Initial : For number 25, 5th bit is not set.
After Set : For number 57, 5th bit is set.

*/
