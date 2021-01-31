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
void DFS1(Graph* g,int u,vector<bool> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS1(g,i,vis);
}
bool isconnected(Graph* g)
{
	vector<bool> vis(g->V);
	
	DFS1(g,0,vis);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	return false;
	
	return true;
}
bool DFS2(Graph* g,int u,int parent,vector<bool> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	{
		if(!vis[i])
		{
			if(DFS2(g,i,u,vis))
			return true;
		}
		else if(i != parent)
		return true;
	}
	return false;
}
bool isCycle(Graph* g)
{
	vector<bool> vis(g->V);
	
	return DFS2(g,0,-1,vis);
}
bool isTree(Graph* g)
{
	if(!isconnected(g))
	return false;
	
	if(isCycle(g))
	return false;
	
	return true;
}
signed main()
{
	Graph *g1=CreateGraph(5);
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);
    
    (isTree(g1)) ? cout << "Graph is Tree\n":
                   cout << "Graph is not Tree\n";

    Graph *g2=CreateGraph(5);
    
    addEdge(g2, 1, 0);
    addEdge(g2, 0, 2);
    addEdge(g2, 2, 1);
    addEdge(g2, 0, 3);
    addEdge(g2, 3, 4);
    
    (isTree(g2)) ? cout << "Graph is Tree\n":
                   cout << "Graph is not Tree\n";
	
	return 0;
}
