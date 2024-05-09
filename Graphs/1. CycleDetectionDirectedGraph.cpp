    // Cycle Detection in directed Graph
    bool dfs(vector<int> adj[],vector<int> &vis, vector<int> &parent, int s ){
        vis[s] = parent[s] = 1;
        for(auto x : adj[s]){
            if(!vis[x] && dfs(adj, vis, parent, x)) return true;
            else if(parent[x] == true) return true;
        }
        parent[s] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0), parent(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(adj, vis, parent, i))  return true;
            }
        }
        return false;
    }
