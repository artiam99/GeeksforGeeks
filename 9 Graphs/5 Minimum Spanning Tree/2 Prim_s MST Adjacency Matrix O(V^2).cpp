#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	int **adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new int*[V];
	for(int i=0;i<V;i++)
	{
		g->adj[i]=new int[V];
		memset(g->adj[i],-1,sizeof(int)*V);
	}
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u][v]=w;
	g->adj[v][u]=w;
}
void PrimsMST(Graph *g)
{
	vector<bool> vis(g->V);
	vector<int> key(g->V,INT_MAX);// Minimum ancestor edge array
	key[0]=0;
	vector<int> parent(g->V,-1);
	
	for(int i=0;i<g->V-1;i++)
	{
		int mn=INT_MAX,ind;
		
		for(int j=0;j<g->V;j++)
		if(!vis[j] && key[j]<=mn)
		{
			mn=key[j];
			ind=j;
		}
		
		vis[ind]=true;
		
		for(int j=0;j<g->V;j++)
		if( g->adj[ind][j]!=-1 && !vis[j] && g->adj[ind][j] < key[j] )
		{
			key[j]=g->adj[ind][j];
			
			parent[j]=ind;
		}
	}
	
	for(int i=1;i<g->V;i++)
	cout<<i<<" "<< parent[i] <<" -> "<< g->adj[i][parent[i]] <<endl;
}
signed main()
{
	int V=9;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1,4);
	addEdge(g,0,7,8);
	addEdge(g,1,2,8);
	addEdge(g,1,7,11);
	addEdge(g,7,8,7);
	addEdge(g,7,6,1);
	addEdge(g,2,8,2);
	addEdge(g,6,8,6);
	addEdge(g,6,5,2);
	addEdge(g,2,5,4);
	addEdge(g,2,3,7);
	addEdge(g,3,5,14);
	addEdge(g,3,4,9);
	addEdge(g,4,5,10);
	
	PrimsMST(g);
	
	return 0;
}
