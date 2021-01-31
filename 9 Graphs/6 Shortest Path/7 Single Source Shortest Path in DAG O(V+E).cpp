#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
struct Graph
{
	int V;
	vector<pair<int,int>> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<pair<int,int>>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u].push_back({v,w});
}
void topo(Graph* g,int u,vector<int> &a,vector<bool> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i.first])
	topo(g,i.first,a,vis);
	
	a.insert(a.begin(),u);
}
void DAGSPT(Graph* g,int src)
{
	vector<int> a;
	
	vector<bool> vis(g->V);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	topo(g,i,a,vis);
	
	vector<int> dist(g->V,INF);
	dist[src]=0;
	
	for(int i=0;i<g->V;i++)
	{
		if(dist[a[i]]!=INF)
		{
			for(auto j:g->adj[a[i]])
			
			if(dist[j.first] > dist[a[i]] + j.second)
			dist[j.first]=dist[a[i]] + j.second;
		}
	}
	
	for(int i=0;i<g->V;i++)
	{
		if(dist[i]==INF)
		cout<<"INF ";
		
		else
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
    addEdge(g, 0, 1, 5); 
    addEdge(g, 0, 2, 3); 
    addEdge(g, 1, 3, 6); 
    addEdge(g, 1, 2, 2); 
    addEdge(g, 2, 4, 4); 
    addEdge(g, 2, 5, 2); 
    addEdge(g, 2, 3, 7); 
    addEdge(g, 3, 4, -1); 
    addEdge(g, 4, 5, -2);
	
	int src=1;
	DAGSPT(g,src);
	
	return 0;
}
