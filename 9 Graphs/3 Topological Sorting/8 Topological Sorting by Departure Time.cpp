#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
void topo(int u,Graph* g,vector<bool> &vis,vector<int> &a,int &timer)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	topo(i,g,vis,a,timer);
	
	a[g->V - (++timer)]=u;
}
void PrintTopoSort(Graph* g)
{
	vector<bool> vis(g->V,false);
	
	vector<int> a(g->V);
	int timer=0;
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	topo(i,g,vis,a,timer);
	
	for(auto i:a)
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,2,3);
	addEdge(g,3,1);
	addEdge(g,4,0);
	addEdge(g,4,1);
	addEdge(g,5,0);
	addEdge(g,5,2);
	
	PrintTopoSort(g);
	
	return 0;
}
