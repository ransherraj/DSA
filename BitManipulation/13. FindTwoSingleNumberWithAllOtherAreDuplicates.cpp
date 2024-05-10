/*

Find the two single numbers when all other number number in array are double except one

-- How it works---
Bucket concept
*first calculate xor of all numbers and store in xorr,
*find the rightmost set bit in xorr and store in rightmost,
*take two variables, and distinguish the element on basis of nums[i] & rightmost then store in a as a = a^nums[i], else b = b^nums[i]
*atlast we get two numbers, as all duplicates, cancel each other in xor operation.

*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, ans = 0, xorr = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        xorr = xorr ^ arr[i];
    }
    
    int rightmost = (xorr & xorr - 1) ^ xorr;
    
    int a = 0, b = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] & rightmost){
            a = a ^ arr[i];
        }
        else{
            b = b ^ arr[i];
        }
    }
    cout << "Single numbers are : " << a << " and " << b <<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
2
8
2 2 3 5 3 1 5 6
8
5 1 1 2 3 3 6 5

Output:
Single numbers are : 1 and 6
Single numbers are : 6 and 2



*/
