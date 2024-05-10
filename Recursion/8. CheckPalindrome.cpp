/*

Check Palindrome


*****Best Approach****
Self Explainatory


*/

#include <bits/stdc++.h>
using namespace std;

bool solve3(string &s, int i, int j){
    if(i > j) return true;
    if(s[i] != s[j]) return false;
    return solve3(s, i+1, j-1);
    
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    bool ans = solve3(s, 0, n-1);
    string res = ans ? "Palindrome" : "Not Palindrome";
    cout<<res<<endl;
}

int main(){
    int t; cin>>t; while(t--)solve();
}


/*

Custom Input :
3
Rajaa
amanama
amma

Output:
Not Palindrome
Palindrome
Palindrome





*/
