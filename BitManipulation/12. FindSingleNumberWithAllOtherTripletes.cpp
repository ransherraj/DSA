/*

Find the single number when all other number number in array are triplet except one

****** Approach 1 *****
--How it works--
* count the bits at each places(unit, 2nd, third, ....) and if it is not multiple of three means, resultant number has bit set at that place, or vice versa.

TC: O(N*32)
SC: O(1)

****** Approach 2 *****
------Middle Pointer-----
*sort numbers, 
*start from i = 1 and 
*check if arr[i] != arr[i-1] return arr[i-1]
*or at end of for loop return arr[n-1];
TC: O(NlogN) -> better than first Approach
SC: O(1)

***** Approach 3 ******
*Bucket rule
*Keep numbers in variable ones and twos, using bitwise operators
TC : O(N)
SC : O(1)

*/

/******* Approach 1 *********/
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 31; i>=0; i--){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if((arr[j] >> i) & 1){
                cnt++ ; 
            }
        }
        if(cnt % 3 == 1) {
            ans = ans | (1 << i);
        }
    }
    cout << "Single number is :" << ans <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/***** Approach 2 *****/
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, ans = 0, flag = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i += 3){
        if(arr[i] != arr[i-1]) {
            ans = arr[i-1];
            flag = 1;
            break;
        }
    }
    if(flag == 0) ans = arr[n-1];
    
    cout << "Single number is :" << ans <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/***** Approach 3 *****/
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int ones = 0, twos = 0;
    for(int i = 0; i<n; i++){
        ones = (ones ^ arr[i]) & ~twos;
        twos = (twos ^ arr[i]) & ~ones;
    }
    ans = ones;
    cout << "Single number is :" << ans <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
7
2 2 3 2 3 3 5
7
5 1 1 5 5 1 2

Output:
Single number is :5
Single number is :2



*/
