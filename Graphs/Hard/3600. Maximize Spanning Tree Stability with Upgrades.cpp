/**

3600. Maximize Spanning Tree Stability with Upgrades

You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:

ui and vi indicates an undirected edge between nodes ui and vi.
si is the strength of the edge.
musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.

The stability of a spanning tree is defined as the minimum strength score among all edges included in it.

Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.

Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

 

Example 1:

Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

Output: 2

Explanation:

Edge [0,1] with strength = 2 must be included in the spanning tree.
Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
The resulting spanning tree includes these two edges with strengths 2 and 6.
The minimum strength in the spanning tree is 2, which is the maximum possible stability.
Example 2:

Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2

Output: 6

Explanation:

Since all edges are optional and up to k = 2 upgrades are allowed.
Upgrade edges [0,1] from 4 to 8 and [1,2] from 3 to 6.
The resulting spanning tree includes these two edges with strengths 8 and 6.
The minimum strength in the tree is 6, which is the maximum possible stability.
Example 3:

Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0

Output: -1

Explanation:

All edges are mandatory and form a cycle, which violates the spanning tree property of acyclicity. Thus, the answer is -1.
 

Constraints:

2 <= n <= 105
1 <= edges.length <= 105
edges[i] = [ui, vi, si, musti]
0 <= ui, vi < n
ui != vi
1 <= si <= 105
musti is either 0 or 1.
0 <= k <= n
There are no duplicate edges.
 
Accepted
60,276/90.3K
Acceptance Rate
66.7%

  **/

class Solution {
public:
    int components;
    vector<int> parent, size;

    int Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return 0;

        components--;
        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return 1;
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        components = n;
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        vector<vector<int>> must, flex;

        for(auto &it : edges){
            if(it[3] == 1) must.push_back(it);
            else flex.push_back(it);
        }

        int mini = INT_MAX;

        for(auto &it : must){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            mini = min(mini, w);

            if(!Union(u, v)){
                return -1;
            }
        }

        sort(flex.begin(), flex.end(), [](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : flex){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(Union(u, v)){
                pq.push(w);
            }
        }

        while(k-- && !pq.empty()){
            int x = pq.top();
            pq.pop();
            mini = min(mini, 2 * x);
        }

        if(components != 1) return -1;

        if(!pq.empty()){
            return min(mini, pq.top());
        }

        return mini;
    }
};
