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
void DFS(Graph* g,int u,vector<bool> &vis,int &odd)
{
	vis[u]=true;
	
	if(g->adj[u].size() & 1)
	odd++;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis,odd);
}
int CountNewEdges(Graph* g)
{
	vector<bool> vis(g->V);
	
	int total_odd = 0, odd_comp = 0, even_comp = 0;
	
	for(int i=0;i<g->V;i++)
	{
		if(!vis[i])
		{
			int odd = 0;
			DFS(g,i,vis,odd);
			
			total_odd += odd;
			
			(odd) ? odd_comp++ : even_comp++;
		}
	}
	
	if(odd_comp == 0 && even_comp ==1)
	return 0;
	
	return total_odd/2 + even_comp;
}
signed main()
{
	Graph *g = CreateGraph(4);
	
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    
    cout<< CountNewEdges(g)<<" new Edges are required to make Graph Elerian"<<endl;
	
	return 0;
}
