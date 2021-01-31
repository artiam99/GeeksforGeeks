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
void AddEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,int parent,vector<int> &color,vector<int> &ans)
{
	ans[u] = color[u];
	
	for(auto i:g->adj[u])
	if(i != parent)
	{
		DFS(g,i,u,color,ans);
		
		ans[u] += max(ans[i] , 0);
	}
}
int MaxDiffSubTree(Graph* g,vector<int> &color)
{	
	vector<int> ans(g->V);
	
	for(int i = 0 ; i < g->V ; i++)
	if(color[i] == 2)
	color[i] = -1;
	
	DFS(g,0,-1,color,ans);  // For Each Sub Tree Checking the Majority of Color 1 ... Color1 if Minor for a SubTree Ignoring it by taking 0
	
	int Color1_Major = *max_element(ans.begin(),ans.end());
	
	fill(ans.begin(),ans.end(),0);
	
	for(int i = 0 ; i < g->V ; i++)
	{
		if(color[i] == 1)
		color[i] = -1;
		
		else
		color[i] = 1;
	}
	
	DFS(g,0,-1,color,ans);  // Same for Color 2
	
	int Color2_Major = *max_element(ans.begin(),ans.end());
	
	return max(Color1_Major , Color2_Major);
}
signed main()
{
	int n = 5;
	
	Graph* g = CreateGraph(n);
	
	AddEdge(g,0,1);
	AddEdge(g,0,2);
	AddEdge(g,1,3);
	AddEdge(g,2,4);
	
	vector<int> color = {1,1,2,2,1};
	
	cout<< MaxDiffSubTree(g,color) <<endl;
	
	return 0;
}
