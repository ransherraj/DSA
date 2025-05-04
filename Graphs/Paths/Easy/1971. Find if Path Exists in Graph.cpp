/*

1971. Find if Path Exists in Graph
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.


*/


// Simple BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        unordered_map<int, vector<int>> adj;
        //int m = edges.size(), n = edges[0].size();
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == des) return true;
            for(auto &node : adj[curr]){
                if(!vis[node]){
                    vis[node] = 1;
                    q.push(node);
                }
            }
        }
        return false;
    }
};

// Simple DFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n);
        stack<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int curr = q.top();
            q.pop();
            if(curr == des) return true;
            for(auto &node : adj[curr]){
                if(!vis[node]){
                    vis[node] = 1;
                    q.push(node);
                }
            }
        }
        return false;
    }
};

// Best Approach Best Time 
class Solution {
public:
    vector<int> parent;
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void makeGroup(int u, int v){
        int pu = find(u);
        int pv = find(v);
        parent[pu] = pv;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        parent.resize(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        for(auto &edge : edges){
            makeGroup(edge[0], edge[1]);
        }

        return find(src) == find(des);
    }
};
