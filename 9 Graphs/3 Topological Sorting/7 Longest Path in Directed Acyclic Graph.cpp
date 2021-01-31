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
}
void topo(Graph* g,int u,stack<int> &st,vector<bool> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i.first])
	topo(g,i.first,st,vis);
	
	st.push(u);
}
void LongestPathTree(Graph* g,int src)
{
	vector<bool> vis(g->V);
	stack<int> st;
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	topo(g,i,st,vis);
	
	vector<int> dist(g->V,INT_MIN);
	dist[src]=0;
	
	while(st.size())
	{
		int u=st.top();  st.pop();
		
		if(dist[u]!=INT_MIN)
		{
			for(auto j:g->adj[u])
			if(dist[j.first] < dist[u] + j.second)
			dist[j.first] = dist[u] + j.second;
		}
	}
	
	for(int i=0;i<g->V;i++)
	{
		if(dist[i]==INT_MIN)
		cout<<"INF ";
		else
		cout<<dist[i]<<" ";
	}
	
	cout<<endl;
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1, 5);  
    addEdge(g, 0, 2, 3);  
    addEdge(g, 1, 3, 6);  
    addEdge(g, 1, 2, 2);  
    addEdge(g, 2, 4, 4);  
    addEdge(g, 2, 5, 2);  
    addEdge(g, 2, 3, 7);  
    addEdge(g, 3, 5, 1);  
    addEdge(g, 3, 4, -1);  
    addEdge(g, 4, 5, -2); 
	
	int src=1;
	
	LongestPathTree(g,src);
	
	return 0;
}
