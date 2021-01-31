#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Edge
{
	int src,dest,wt;
};
struct Graph
{
	int V,E;
	list<int> *adj;
	Edge *edge;
};
bool comp(Edge x,Edge y)
{
	return x.wt > y.wt;
}
Graph* CreateGraph(int V,int E)
{
	Graph* g=new Graph;
	
	g->V=V;
	g->E=E;
	
	g->adj=new list<int>[V];
	
	g->edge=new Edge[E];
	
	return g;
}
void addEdge(Graph* g,int i,int u,int v,int w)
{
	g->edge[i].src=u;
	g->edge[i].dest=v;
	g->edge[i].wt=w;
	
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,vector<bool> &vis)
{
	vis[u]=true;
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis);
}
bool isconnected(Graph* g,int u,int v)
{
	vector<bool> vis(g->V);
	DFS(g,u,vis);
	return vis[v];
}
void ReverseDeleteMST(Graph* g)
{
	sort(g->edge , g->edge + g->E , comp);
	
	for(int i=0;i<g->E;i++)
	{
		int u=g->edge[i].src;
		int v=g->edge[i].dest;
		
		g->adj[u].remove(v);
		g->adj[v].remove(u);
		
		if(!isconnected(g,u,v))
		{
			g->adj[u].push_back(v);
        	g->adj[v].push_back(u);
        	
        	cout<<u<<" "<<v<<" -> "<<g->edge[i].wt<<endl;
		}
	}
}
signed main()
{
	int V=9,E=14;
	
	Graph* g=CreateGraph(V,E);
	
	addEdge(g,0,0,1,4);
	addEdge(g,1,0,7,8);
	addEdge(g,2,1,2,8);
	addEdge(g,3,1,7,11);
	addEdge(g,4,7,8,7);
	addEdge(g,5,7,6,1);
	addEdge(g,6,2,8,2);
	addEdge(g,7,6,8,6);
	addEdge(g,8,6,5,2);
	addEdge(g,9,2,5,4);
	addEdge(g,10,2,3,7);
	addEdge(g,11,3,5,14);
	addEdge(g,12,3,4,9);
	addEdge(g,13,4,5,10);
	
	ReverseDeleteMST(g);
	
	return 0;
}
