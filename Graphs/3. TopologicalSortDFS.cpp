void helpSort(vector<int> adj[], vector<int> &vis, stack<int> &ans, int s){
	    vis[s] = 1;
	    for (auto x : adj[s]){
	        if(!vis[x]){
	            helpSort(adj, vis, ans, x);
	        }
	    }
	    ans.push(s);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
    
	    //dfs
	    vector<int>  vis(V), res;
	    stack<int> ans;
	    
	    for(int i = 0; i<V; i++)
	    {
	        if(!vis[i]){
	            helpSort(adj, vis, ans, i);
	        }
	    }
	     while(!ans.empty()){
	         int e = ans.top();
	         ans.pop();
	         res.push_back(e);
	     }
	    return res;
	}
