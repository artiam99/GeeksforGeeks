#include<bits/stdc++.h>
using namespace std;
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
		memset(g->adj[i],0,sizeof(int)*V);
	}
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u][v]=w;
}
bool BFS(Graph* g,int s,int t,vector<int> &parent)
{
	vector<bool> vis(g->V);
	
	queue<int> q;
	
	q.push(s);
	vis[s]=true;
	parent[s]=-1;
	
	while(q.size())
	{
		int u=q.front(); q.pop();
		
		for(int i=0;i<g->V;i++)
		if(!vis[i] && g->adj[u][i])
		{
			q.push(i);
			vis[i]=true;
			parent[i]=u;
		}
	}
	return vis[t];
}
void DFS(Graph* g,int u,vector<bool> &vis)
{
	vis[u]=true;
	for(int i=0;i<g->V;i++)
	if(!vis[i] && g->adj[u][i])
	DFS(g,i,vis);
}
void Minimum_Cut(Graph* g,int s,int t)
{
	vector<vector<int>> adj(g->V,vector<int>(g->V,0));
	
	for(int i=0;i<g->V;i++)
	{
		for(int j=0;j<g->V;j++)
		adj[i][j]=g->adj[i][j];
	}

	vector<int> parent(g->V,-1);
	
	while(BFS(g,s,t,parent))
	{
		int flow=INT_MAX;
		
		for(int i=t;i!=s;i=parent[i])
		flow = min(flow , g->adj[parent[i]][i]);
		
		for(int i=t;i!=s;i=parent[i])
		{
			g->adj[parent[i]][i] -= flow;
			
			g->adj[i][parent[i]] += flow;
		}
	}
	
	vector<bool> vis(g->V);
	DFS(g,s,vis);
	
	for(int i=0;i<g->V;i++)
	{
			for(int j=0;j<g->V;j++)
			if(vis[i] && !vis[j] && adj[i][j])
			cout<<i<<" "<<j<<endl;
	}
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1,16);
	addEdge(g,0,2,13);
	addEdge(g,1,2,10);
	addEdge(g,1,3,12);
	addEdge(g,2,1,4);
	addEdge(g,2,4,14);
	addEdge(g,3,2,9);
	addEdge(g,3,5,20);
	addEdge(g,4,3,7);
	addEdge(g,4,5,4);
	
	int s=0,t=5;
	
	Minimum_Cut(g,s,t);
	
	return 0;
}
