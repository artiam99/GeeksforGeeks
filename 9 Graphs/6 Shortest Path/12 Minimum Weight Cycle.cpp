#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int u,v,w;
};
struct Graph
{
	int V;
	list<pair<int,int>> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new list<pair<int,int>>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u].push_back({v,w});
	g->adj[v].push_back({u,w});
}
int ShortestPath(Graph *g,int u,int v)
{
	vector<int> dist(g->V,INT_MAX);
	dist[u]=0;
	
	vector<bool> vis(g->V);
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,u});
	
	while(pq.size())
	{
		u=pq.top().second; pq.pop();
		
		if(!vis[u])
		{
			vis[u]=true;
			
			for(auto i:g->adj[u])
			if(!vis[i.first] && dist[i.first] > dist[u] + i.second)
			{
				dist[i.first] = dist[u] + i.second;
				pq.push({dist[i.first],i.first});
			}
		}
	}
	return dist[v];
}
int MinimumWeightCycle(Graph* g)
{
	vector<Edge> edge;
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		{
			Edge e;
			e.u=i;
			e.v=j.first;
			e.w=j.second;
			edge.push_back(e);
		}
	}
	
	int res=INT_MAX;
	
	for(int i=0;i<edge.size();i++)
	{
		g->adj[edge[i].u].remove({edge[i].v,edge[i].w});
		g->adj[edge[i].v].remove({edge[i].u,edge[i].w});
		
		res=min(res,ShortestPath(g,edge[i].u,edge[i].v)+edge[i].w);
		
		g->adj[edge[i].u].push_back({edge[i].v,edge[i].w});
		g->adj[edge[i].v].push_back({edge[i].u,edge[i].w});
	}
	return res;
}
signed main()
{
	int V=9,E=14;
	
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
	
	cout<<MinimumWeightCycle(g)<<endl;
	
	return 0;
}
