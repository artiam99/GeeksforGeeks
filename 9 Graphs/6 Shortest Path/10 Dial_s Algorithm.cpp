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
void DialsAlgo(Graph* g,int src,int W)
{
	vector<pair<int,list<int>::iterator>> dist(g->V);
	for(int i=0;i<g->V;i++)
	dist[i].first=INT_MAX;
	
	dist[src].first=0;
	
	list<int> Bucket[g->V*W];
	
	Bucket[0].push_front(src);
	
	int idx=0;
	
	while(1)
	{
		while(idx < W*g->V && Bucket[idx].size() == 0)
		idx++;
		
		if(idx == W*g->V)
		break;
		
		int u=Bucket[idx].front();
		
		Bucket[idx].pop_front();
		
		for(auto i:g->adj[u])
		{
			if(dist[i.first].first > dist[u].first + i.second)
			{
				if(dist[i.first].first != INT_MAX)
				Bucket[dist[i.first].first].erase(dist[i.first].second);
				
				dist[i.first].first = dist[u].first + i.second;
				
				Bucket[dist[i.first].first].push_front(i.first);
				
				dist[i.first].second = Bucket[dist[i.first].first].begin();
			}
		}
	}
	
	for(int i=0;i<g->V;i++)
	cout<<i<<" --> "<<dist[i].first<<endl;
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
	
	int src=0,W=14;
	
	DialsAlgo(g,src,W);
	
	return 0;
}
