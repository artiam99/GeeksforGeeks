#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	vector<pair<int,int>> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<pair<int,int>>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u].push_back({v,w});
	g->adj[v].push_back({u,w});
}
void SPTBinaryEdges(Graph* g,int src)
{
	vector<int> dist(g->V,INT_MAX);
	
	deque<int> dq;
	
	dq.push_front(src);
	dist[src]=0;
	
	while(dq.size())
	{
		int u=dq.front();

		dq.pop_front();
		
		for(auto i:g->adj[u])
		{
			if( dist[i.first] > dist[u] + i.second)
			{
				dist[i.first] = dist[u] + i.second;
				
				if(i.second)
				dq.push_back(i.first);
				
				else
				dq.push_front(i.first);
			}
		}
	}
	
	for(auto i:dist)
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	int V=9;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1, 0); 
    addEdge(g, 0, 7, 1); 
    addEdge(g, 1, 7, 1); 
    addEdge(g, 1, 2, 1); 
    addEdge(g, 2, 3, 0); 
    addEdge(g, 2, 5, 0); 
    addEdge(g, 2, 8, 1); 
    addEdge(g, 3, 4, 1); 
    addEdge(g, 3, 5, 1); 
    addEdge(g, 4, 5, 1); 
    addEdge(g, 5, 6, 1); 
    addEdge(g, 6, 7, 1); 
    addEdge(g, 7, 8, 1); 
	
	int src=0;
	
	SPTBinaryEdges(g,src);
	
	return 0;
}
