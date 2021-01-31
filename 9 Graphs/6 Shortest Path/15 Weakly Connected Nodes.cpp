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
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,vector<bool> &vis,int &deg,int &node)
{
	vis[u]=true;
	
	node++;
	
	deg += g->adj[u].size();
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis,deg,node);
}
int WeaklyConnectedNodes(Graph* g)
{
	int cnt=0;
	
	vector<bool> vis(g->V);
	
	int deg=0,node=0;
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	{
		deg=0,node=0;
		
		DFS(g,i,vis,deg,node);
		
		if(deg/2 == node-1)// Graph is spanning Tree or not ... if so , count root's indgree
		cnt++;
	}
	return cnt;
}
signed main()
{	
	Graph* g=CreateGraph(6);
	
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 3, 4);
	addEdge(g, 3, 5);
	
	cout<< WeaklyConnectedNodes(g) <<endl;
	
	return 0;
}
