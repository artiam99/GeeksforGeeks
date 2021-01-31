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
void DFS(Graph *g,int u,vector<bool> &vis,vector<int> &disc,vector<int> &low,vector<int> &parent,int &timer)
{
	vis[u]=true;
	
	disc[u]=low[u]=++timer;
	
	for(auto i:g->adj[u])
	{
		if(!vis[i])
		{
			parent[i]=u;
			
			DFS(g,i,vis,disc,low,parent,timer);
			
			low[u]=min(low[u],low[i]);
			
			if(low[i] > disc[u])
			cout<<u<<" --- "<<i<<"   ";
		}
		else if(i != parent[u])
		low[u]=min(low[u],disc[i]);
	}
}
void PrintBridges(Graph *g)
{
	vector<bool> vis(g->V);
	vector<int> disc(g->V);
	vector<int> low(g->V);
	vector<int> parent(g->V,-1);
	
	for(int i=0;i<g->V;i++)
	{
		int timer=0;
		if(!vis[i])
		DFS(g,i,vis,disc,low,parent,timer);
	}
	cout<<endl<<endl;
}
signed main()
{
    Graph *g1=CreateGraph(5);
    
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 1);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);
    
	cout << "Bridges in first graph : ";
	
	PrintBridges(g1);


    Graph *g2=CreateGraph(4);
    
    addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);
    addEdge(g2, 2, 3);
    
    cout << "\nBridges in second graph : ";
    
	PrintBridges(g2);


    Graph *g3=CreateGraph(7);
    
    addEdge(g3, 0, 1);
    addEdge(g3, 1, 2);
    addEdge(g3, 2, 0);
    addEdge(g3, 1, 3);
    addEdge(g3, 1, 4);
    addEdge(g3, 1, 6);
    addEdge(g3, 3, 5);
    addEdge(g3, 4, 5);
    
    cout << "\nBridges in third graph : ";
    
    PrintBridges(g3);
	
	return 0;
}
