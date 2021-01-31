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
void PrimsMST(Graph *g)
{
	vector<bool> vis(g->V);
	vector<int> key(g->V,INT_MAX);//Minimum ancestor edge array
	key[0]=0;
	vector<pair<int,int>> parent(g->V);
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,0});
	
	while(pq.size())
	{
		int u=pq.top().second;
		
		pq.pop();
		
		if(!vis[u])
		{
			vis[u]=true;
			
			for(int i=0;i<g->adj[u].size();i++)
			{
				int v=g->adj[u][i].first;
				int w=g->adj[u][i].second;
				
				if(!vis[v] && key[v] > w)
				{
					key[v]=w;
					
					pq.push({w,v});
					
					parent[v]={u,w};
				}
			}
		}
	}
	
	for(int i=1;i<g->V;i++)
	cout<<i<<" "<<parent[i].first<<" -> "<<parent[i].second<<endl;
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
