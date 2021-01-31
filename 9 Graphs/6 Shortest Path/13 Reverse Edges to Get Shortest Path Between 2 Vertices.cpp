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
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back({v,0});
	g->adj[v].push_back({u,1});
}
int EdgeSwap(Graph* g,int src,int dest)
{
	vector<int> dist(g->V,INT_MAX);
	dist[src]=0;
	
	deque<int> dq;
	
	dq.push_front(src);
	
	while(dq.size())
	{
		int u=dq.front(); 
		
		dq.pop_front();
		
		for(auto i:g->adj[u])
		{
			if(dist[i.first] > dist[u] + i.second)
			{
				dist[i.first] = dist[u] + i.second;
				
				if(i.second)
				dq.push_back(i.first);
				else
				dq.push_front(i.first);
			}
		}
	}
	
	return dist[dest];
}
signed main()
{
	int V=7;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,2,1);
	addEdge(g,2,3);
	addEdge(g,4,5);
	addEdge(g,5,1);
	addEdge(g,6,3);
	addEdge(g,6,4);
	
	int src=0,dest=6;
	
	cout<<EdgeSwap(g,src,dest)<<endl;
	
	return 0;
}
