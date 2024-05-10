/*

Divide N by D without using divide operator


*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,d, ans = 0;
    cin >>n>>d;
    int sign = 1;
    if((n > 0 && d < 0) || (n < 0 && d > 0)) sign = -1;
    
    int tempN = n, tempD = d;
    
    n = abs(n);
    d = abs(d);
    
    while(n >= d){
        int cnt = 0;
        while(n >= (d << (cnt + 1)) ){
            cnt += 1;
        }
        ans += (1 << cnt);
        n -= (d << cnt);
        
    }
    
    if(ans == (1 << 31) && sign == 1){
        ans = INT_MAX;
    }
    if(ans == (1 << 31) && sign == -1){
        ans = INT_MIN;
    }
    
    ans = sign == 1 ? ans : -ans;
    
    cout << "Division of "<<tempN<<" by " << tempD << " withou using / operator is " << ans <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
9 2
30 7

Output:
Division of 9 by 2 withou using / operator is 4
Division of 30 by 7 withou using / operator is 4



*/
