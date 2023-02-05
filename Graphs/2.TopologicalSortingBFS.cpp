vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    //with bfs
	    vector<int> ans, indegree(V, 0);
	    for(int i = 0; i<V; i++){
	        for(auto x : adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int e = q.front();
	        q.pop();
	        ans.push_back(e);
	        for(auto x : adj[e]){
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    return ans;
	    
	}
