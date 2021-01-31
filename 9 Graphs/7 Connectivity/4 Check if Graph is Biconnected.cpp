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
void DFS(Graph* g,int u,vector<bool> &vis,vector<int> &disc,vector<int> &low,vector<int> &parent,int &aps,int &timer)
{
	vis[u]=true;
	
	int children=0;
	
	disc[u]=low[u]=++timer;
	
	for(auto i:g->adj[u])
	{
		if(!vis[i])
		{
			parent[i]=u;
			
			children++;
			
			DFS(g,i,vis,disc,low,parent,aps,timer);
			
			low[u]=min(low[u],low[i]);
			
			if(parent[u]==-1 && children > 1)
			aps++;
			
			else if(parent[u]!=-1 && low[i]>=disc[u])
			aps++;
		}
		else if(i!=parent[u])
		low[u]=min(low[u],disc[i]);
	}
}
bool isBiconnected(Graph* g)
{
	vector<bool> vis(g->V);
	vector<int> disc(g->V);
	vector<int> low(g->V);
	vector<int> parent(g->V,-1);
	int aps=0;
	int timer=0;
	
	DFS(g,0,vis,disc,low,parent,aps,timer);
	
	for(auto i:vis)
	if(!i)
	return false;
	
	return (aps==0);
}
signed main()
{
	Graph *g1=CreateGraph(2); 
    addEdge(g1, 0, 1); 
    (isBiconnected(g1))? cout << "Yes\n" : cout << "No\n"; 
  
    Graph *g2=CreateGraph(5); 
    addEdge(g2, 1, 0); 
    addEdge(g2, 0, 2); 
    addEdge(g2, 2, 1); 
    addEdge(g2, 0, 3); 
    addEdge(g2, 3, 4); 
    addEdge(g2, 2, 4); 
    (isBiconnected(g2))? cout << "Yes\n" : cout << "No\n";
  
    Graph *g3=CreateGraph(3); 
    addEdge(g3, 0, 1); 
    addEdge(g3, 1, 2); 
    (isBiconnected(g3))? cout << "Yes\n" : cout << "No\n";
  
    Graph *g4=CreateGraph(5); 
    addEdge(g4, 1, 0); 
    addEdge(g4, 0, 2); 
    addEdge(g4, 2, 1); 
    addEdge(g4, 0, 3); 
    addEdge(g4, 3, 4); 
    (isBiconnected(g4))? cout << "Yes\n" : cout << "No\n";
  
    Graph *g5=CreateGraph(3); 
    addEdge(g5, 0, 1); 
    addEdge(g5, 1, 2); 
    addEdge(g5, 2, 0); 
    (isBiconnected(g5))? cout << "Yes\n" : cout << "No\n";
	
	return 0;
}
