#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
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
		
		for(int j=0;j<V;j++)
		g->adj[i][j]=INF;
		
		g->adj[i][i]=0;
	}
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u][v]=w;
}
int ShortestPath(Graph* g,int u,int v,int k)
{
	if(k==0 && u==v) return 0;// SelfLoop
	
	if(k<=0) return INF;
	
	if(k==1 && g->adj[u][v]!=INF) return g->adj[u][v];
	
	int res=INF;
	
	for(int i=0;i<g->V;i++)
	{
		if(g->adj[u][i]!=INF && i!=u && i!=v)
		{
			int rec_res=ShortestPath(g,i,v,k-1);
			
			if(rec_res!=INF)
			res=min(res,rec_res + g->adj[u][i]);
		}
	}
	
	return res;
}
signed main()
{
	int V=4;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1,10);
	addEdge(g,0,2,3);
	addEdge(g,0,3,2);
	addEdge(g,1,3,7);
	addEdge(g,2,3,6);
		
	int u=0,v=3,k=2;
	cout<<ShortestPath(g,u,v,k)<<endl;
	
	return 0;
}
