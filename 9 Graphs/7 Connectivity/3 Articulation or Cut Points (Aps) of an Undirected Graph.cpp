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
void FindApsUntill(Graph* g,int u,vector<bool> &vis,vector<int> &disc,vector<int> &low,vector<int> &parent,vector<bool> &Aps,int &time)
{
	vis[u]=true;
	
	int children=0;
	
	disc[u]=low[u]=++time;
	
	
	for(auto i:g->adj[u])
	{
		if(!vis[i])
		{
			parent[i]=u;
			
			children++;
			
			FindApsUntill(g,i,vis,disc,low,parent,Aps,time);
			
			low[u]=min(low[u],low[i]);
			
			if(parent[u]==-1 && children>1)
			Aps[u]=true;
			
			else if(parent[u]!=-1 && low[i]>=disc[u])
			Aps[u]=true;
		}
		
		else if(parent[u] != i)
		low[u]=min(low[u],disc[i]);
	}
}
void FindAps(Graph* g)
{
	vector<bool> vis(g->V);
	vector<int> disc(g->V);
	vector<int> low(g->V);
	vector<int> parent(g->V,-1);
	vector<bool> Aps(g->V);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	{
		int time=0;
		FindApsUntill(g,i,vis,disc,low,parent,Aps,time);
	}
	
	for(int i=0;i<g->V;i++)
	if(Aps[i])
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
    Graph *g1 = CreateGraph(3);
    
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 1);
    
    cout<<"Articulation points in first graph : ";
    FindAps(g1);

    Graph *g2=CreateGraph(4);
    
    addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);
    addEdge(g2, 2, 3);
    
    cout<<"\nArticulation points in second graph : ";
    FindAps(g2);
    
    Graph *g3=CreateGraph(7);
    
    addEdge(g3, 0, 1);
    addEdge(g3, 1, 2);
    addEdge(g3, 2, 0);
    addEdge(g3, 1, 3);
    addEdge(g3, 1, 4);
    addEdge(g3, 1, 6);
    addEdge(g3, 3, 5);
    addEdge(g3, 4, 5);
    
    cout<<"\nArticulation points in third graph : ";
	FindAps(g3);
	
	return 0;
}
