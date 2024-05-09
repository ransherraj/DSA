
#include <bits/stdc++.h>
#define INT_PAIR pair<int, int> 
using namespace std;

bool compare(INT_PAIR a, INT_PAIR b){
    return (a.first > b.first);
}

bool compare1(INT_PAIR a, INT_PAIR b){
    return (a.first < b.first);
}

bool compare2(INT_PAIR a, INT_PAIR b){
    return (a.second > b.second);
}

bool compare3(INT_PAIR a, INT_PAIR b){
    return (a.second < b.second);
}


void solve(){
    int n; cin>>n;
    vector<INT_PAIR> v(n);
    priority_queue<INT_PAIR, vector<INT_PAIR>, greater<INT_PAIR>> pq;
    
    for(int i = 0; i<n; i++){
        cin>>v[i].first>>v[i].second;
        pq.push({v[i].first,v[i].second});
    }
    
    cout<<"Printing using Array: \n";
    
    for(int i = 0; i<n; i++){
        cout<<v[i].first<<"  "<<v[i].second<<endl;
    }
    
    cout<<"Printing using priority Queue: \n";
    
    while(!pq.empty()){
        INT_PAIR temp = pq.top();
        pq.pop();
        cout<<temp.first<<"  "<<temp.second<<endl;
    }
    
    cout<<"Printing Sorted elements using cmp functions 1: \n";
    
    vector<INT_PAIR> p1 = v;
    sort(p1.begin(), p1.end(), compare);
    
    for(int i = 0; i<n; i++){
        cout<<p1[i].first<<"  "<<p1[i].second<<endl;
    }
    
    cout<<"Printing Sorted elements using cmp functions 2: \n";
    
    p1 = v;
    sort(p1.begin(), p1.end(), compare1);
    
    for(int i = 0; i<n; i++){
        cout<<p1[i].first<<"  "<<p1[i].second<<endl;
    }
    
    cout<<"Printing Sorted elements using cmp functions 3: \n";
    
    p1 = v;
    sort(p1.begin(), p1.end(), compare2);
    
    for(int i = 0; i<n; i++){
        cout<<p1[i].first<<"  "<<p1[i].second<<endl;
    }
    
    cout<<"Printing Sorted elements using cmp functions 4: \n";
    
    p1 = v;
    sort(p1.begin(), p1.end(), compare3);
    
    for(int i = 0; i<n; i++){
        cout<<p1[i].first<<"  "<<p1[i].second<<endl;
    }
}

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
}


/* 

Input:

1
4
1 2
3 4
4 5
3 2

Output:

Printing using Array: 
1  2
3  4
4  5
3  2
Printing using priority Queue: 
1  2
3  2
3  4
4  5
Printing Sorted elements using cmp functions 1: 
4  5
3  4
3  2
1  2
Printing Sorted elements using cmp functions 2: 
1  2
3  4
3  2
4  5
Printing Sorted elements using cmp functions 3: 
4  5
3  4
1  2
3  2
Printing Sorted elements using cmp functions 4: 
1  2
3  2
3  4
4  5


*/
