#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int V;
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
void DFS(Graph* g,int u,vector<bool> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis);
}
Graph* Transpose(Graph* g)
{
	Graph* gt=new Graph;
	
	gt->V=g->V;
	
	gt->adj=new vector<int>[g->V];
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		gt->adj[j].push_back(i);
	}
	return gt;
}
bool StronglyConnected(Graph* g)
{
	vector<bool> vis(g->V);
	
	DFS(g,0,vis);
	
	for(auto i:vis)
	if(!i)
	return false;
	
	fill(vis.begin(),vis.end(),false);
	
	Graph* gt=Transpose(g);
	
	DFS(gt,0,vis);
	
	for(auto i:vis)
	if(!i)
	return false;
	
	return true;
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1); 
    addEdge(g, 1, 2); 
    addEdge(g, 2, 3); 
    addEdge(g, 3, 0); 
    addEdge(g, 2, 4); 
    addEdge(g, 4, 2);
	
	if(StronglyConnected(g))
	cout<<"Strongly Connected"<<endl;
	else
	cout<<"Not Strongly Connected"<<endl;
	
	return 0;
}
