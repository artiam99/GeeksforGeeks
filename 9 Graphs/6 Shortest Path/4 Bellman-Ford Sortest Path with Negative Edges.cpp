#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int u,v,w;
};
struct Graph
{
	int V,E;
	Edge *edge;
};
Graph* CreateGraph(int V,int E)
{
	Graph* g=new Graph;
	
	g->V=V;
	g->E=E;
	
	g->edge=new Edge[E];
		
	return g;
}
void addEdge(Graph* g,int i,int u,int v,int w)
{
	g->edge[i].u=u;
	g->edge[i].v=v;
	g->edge[i].w=w;
}
void BellmanFord(Graph* g)
{
	vector<int> dist(g->V,INT_MAX);
	dist[0]=0;
	
	for(int i=1;i<g->V;i++)
	{
		for(int j=0;j<g->E;j++)
		{
			if( dist[g->edge[j].u] != INT_MAX && dist[g->edge[j].v] > dist[g->edge[j].u] + g->edge[j].w)
			dist[g->edge[j].v] = dist[g->edge[j].u] + g->edge[j].w;
		}
	}
	
	for(int i=0;i<g->E;i++)
	if(dist[g->edge[i].v] > dist[g->edge[i].u] + g->edge[i].w)
	{
		cout<<"Negative Cycle Present"<<endl;
		return;
	}
	
	for(int i=1;i<g->V;i++)
	cout<<i<<" -> "<<dist[i]<<endl;
}
signed main()
{
	int V=5,E=8;
	
	Graph* g=CreateGraph(V,E);
	
	addEdge(g,0,0,1,-1);
	addEdge(g,1,0,2,4);
	addEdge(g,2,1,2,3);
	addEdge(g,3,1,3,2);
	addEdge(g,4,1,4,2);
	addEdge(g,5,3,1,1);
	addEdge(g,6,3,2,5);
	addEdge(g,7,4,3,-3);
	
	BellmanFord(g);
	
	return 0;
}
