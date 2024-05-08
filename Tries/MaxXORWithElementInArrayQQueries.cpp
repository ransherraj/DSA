/*
Problem statement
You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers. You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].

The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’.

You should return an array/list consisting of ‘N’ integers where the ‘i-th’ integer is the answer of ‘QUERIES[i]’.

Note:

1. If all integers are greater than ‘Ai’ in array/list ‘ARR’  then the answer to this ith query will be -1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1 <= N, M <= 10000
0 <= ARR[i], Xi, Ai <= 10^9

Where ‘T’ is the number of test cases, 'N' is the size of ‘ARR’, ‘M’  is the number of queries, ‘ARR[i]’ is an element of array/list ‘ARR’ and ‘Xi’, ‘Ai’ are the integers in ‘QUERIES[i]’.  

Time limit: 1 sec
Sample Input 1:
2
5 2
0 1 2 3 4
1 3
5 6
1 1
1
1 0  
Sample Output 1:
3 7
-1
Explanation of sample input 1:
In the first test case, the answer of query [1, 3] is 3 because 1^2 = 3 and 2 <= 3,  and the answer of query [5, 6] is 7 because  5 ^ 2 = 7 and 2 <= 6.

In the second test case, no element is less than or equal to 0 in the given array ‘ARR’.
Sample Input 2:
2
6 3
6 6 3 5 2 4
6 3
8 1
12 4 
5 2
0 0 0 0 0
1 0
1 1
Sample Output 2:
5 -1 15
1 1
*/

#include<bits/stdc++.h>

struct Node{
	Node* childNode[2];

	bool containsKey(int key){
		return childNode[key] != NULL;
	}

	void put(Node* node, int num){
		childNode[num] = node;
	}

	Node* get(int num){
		return childNode[num];
	}
};

class Trie{
	private:
	Node* root;

	public:
	Trie(){
		root = new Node();
	}

	void insertKey(int num){
		//cout<<"Hi"<<endl;
		Node* node = root;
		for(int i = 31; i>=0; i--){
			int bit = (num>>i) & 1;
			if(!node->containsKey(bit)){
				node->put(new Node(), bit);
			}
			node = node->get(bit);
		}
	}

	int getMaxXOR(int num){
		Node* node = root;
		int ans = 0;
		for(int i = 31; i>=0; i--){
			int bit = (num>>i) & 1;
			if(node->containsKey(1-bit)){
				ans = ans | (1 << i);
				node = node->get(1-bit);
			}
			else{
				node = node->get(bit);
			}	
		}
		return ans;
	}
};



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	Trie obj;
	int n = arr.size();
	int m = queries.size();
	int ind = 0;
	vector<int> ans(m, 0);
	sort(arr.begin(), arr.end());
	//cout<<"Hi"<<endl;
	vector<pair<int, pair<int, int>>> Q;
	for(int i = 0; i<m; i++){
		Q.push_back({queries[i][1], {queries[i][0], i}});
	}
	sort(Q.begin(), Q.end());

	for(int i = 0; i<m; i++){
		int A = Q[i].first;
		int X = Q[i].second.first;
		int Qind = Q[i].second.second;
		while(ind < n && arr[ind] <= A){
			obj.insertKey(arr[ind]);
			ind++;
		}
		if(ind == 0) ans[Qind] = -1;
		else ans[Qind] = obj.getMaxXOR(X);
	}
	return ans;
}
