/*

Find the single number when all other number number in array are duplicate except one


======== Brute Force ======== :
* take a map and keep number as key and count as value, while traversing in array
* Traverse map and if count == 1 return number

TC : N * log(size of map)
SC : O(size of map)

=========== Best Approach ==== :
* XOR of two same numbers = 0
* All duplicates will cancel out each other and only single number return at last.

TC : O(N)
SC : O(1)

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
