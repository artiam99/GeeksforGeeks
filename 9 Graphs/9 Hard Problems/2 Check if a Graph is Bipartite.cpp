#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
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
bool DFS(Graph* g,int u,vector<int> &color,int cr)
{
	if(color[u]!=-1)
	return (color[u]==cr);
	
	color[u]=cr;
	
	for(auto i:g->adj[u])
	if(!DFS(g,i,color,1-cr))
	return false;
	
	return true;
}
bool isBipartite(Graph* g)
{
	vector<int> color(g->V,-1);
	
	for(int i=0;i<g->V;i++)
	if(color[i]==-1 && !DFS(g,i,color,1))
	return false;
	
	return true;
}
signed main()
{
	Graph *g=CreateGraph(4);
    
	addEdge(g, 0, 1);
    addEdge(g, 0, 3);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    
	if(isBipartite(g))
	cout<< "Bipartite" <<endl;
	else
	cout<< "Not Bipartite" <<endl;
  
    return 0;
}
