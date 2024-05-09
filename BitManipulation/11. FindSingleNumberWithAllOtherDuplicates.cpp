/*

Find the single number when all other number number in array are duplicate except one

*/

#include <bits/stdc++.h>

using namespace std;



void solve(){
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        ans = ans ^ temp;
    }
    cout << "Single number is :" << ans <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
5
1 2 3 2 1
7
2 3 10 5 5 3 2

Output:
Single number is :3
Single number is :10



*/
