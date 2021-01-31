#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int V;
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g = new Graph;
	
	g->V = V;
	
	g->adj = new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	u--; v--;
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,vector<bool> &vis,int &N,int &D)
{
	vis[u] = true;
	N++;
	D += g->adj[u].size();
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis,N,D);
}
int Single_Cycle_Components(Graph* g)
{
	vector<bool> vis(g->V);
	
	int ans = 0;
	
	for(int i = 0 ; i < g->V ; i++)
	if(!vis[i])
	{
		int N = 0 , D = 0;
		
		DFS(g,i,vis,N,D);
		
		if(N * 2 == D)
		ans++;
	}
	return ans;
}
signed main()
{
	int V = 15;
	
	Graph* g = CreateGraph(V);
	
	addEdge(g, 1, 10); 
    addEdge(g, 1, 5); 
    addEdge(g, 5, 10); 
    addEdge(g, 2, 9); 
    addEdge(g, 9, 15); 
    addEdge(g, 2, 15); 
    addEdge(g, 2, 12); 
    addEdge(g, 12, 15); 
    addEdge(g, 13, 8); 
    addEdge(g, 6, 14); 
    addEdge(g, 14, 3); 
    addEdge(g, 3, 7); 
    addEdge(g, 7, 11); 
    addEdge(g, 11, 6); 	
	
	cout<< Single_Cycle_Components(g) << endl;
	
	return 0;
}
