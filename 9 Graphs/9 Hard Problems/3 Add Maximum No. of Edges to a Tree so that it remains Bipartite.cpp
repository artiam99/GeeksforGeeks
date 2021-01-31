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
void DFS(Graph* g,int u,vector<bool> &vis,bool cr,int &cr1,int &cr2)
{
	vis[u]=true;
	
	(cr) ? cr1++ : cr2++;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis,!cr,cr1,cr2);
}
int AddBipartiteEdges(Graph* g)
{
	vector<bool> vis(g->V);
	int cr1=0,cr2=0;
	
	DFS(g,0,vis,1,cr1,cr2);
	
	return (cr1*cr2) - (g->V - 1);// Maximum number of Bipartite Edeges - Curr Edges .... Maximum Number of Bipartite Edges in Graph of n Vertices is floor((n*n)/4) 
}                                //  n1 * n2 ... n1 number of vertices in set1 and n2 for set2 .... Maximum Edges n1 * n2 and n1 + n2 = n ... So n1 * n2 is maximum when n1 = n2 = n/2
signed main()
{
	Graph *g=CreateGraph(5);
    
	addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    
	cout<< AddBipartiteEdges(g) <<endl;
  
    return 0;
}
