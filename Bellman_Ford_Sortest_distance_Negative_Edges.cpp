
//Bellman ford implementation

#include<bits/stdc++.h>
using namespace std;

#define maxx 1000000

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, V;
	cin>>n>>V;

	vector<pair<pair<int, int>, int>> graph;

	for(int i = 0; i<V; i++){
		int u, v, w;
		cin>>u>>v>>w;
		graph.push_back({{u, v}, w});
	}

	// for(int i = 0; i<V; i++){
	// 	cout<<graph[i].first.first<<" "<<graph[i].first.second<<" "<<graph[i].second<<endl;
	// }

	vector<int> dist(n, maxx);
	dist[0] = 0;

	// for(int i = 0; i<n; i++){
	// 	cout<<dist[i]<<endl;
	// }

	for(int i = 0; i<n-1; i++){
		for(auto x : graph){
			int u = x.first.first;
			int v = x.first.second;
			int w = x.second;

			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
			}
		}
	}

	vector<int> test = dist;

	for(auto x : graph){
			int u = x.first.first;
			int v = x.first.second;
			int w = x.second;

			if(test[u] + w < test[v]){
				test[v] = test[u] + w;
			}
	}

	if(test != dist){
		cout<<" Negative Cycle available"<<endl;
	}
	else
	for(int i = 0; i<n; i++){
		cout<<dist[i]<<endl;
	}

}
             
             
