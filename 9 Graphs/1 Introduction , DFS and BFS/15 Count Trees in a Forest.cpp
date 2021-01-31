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
	g->adj[v].push_back(u);
}
void DFT(Graph* g,int x,vector<bool> &vis)
{
	if(vis[x])
	return;
	
	vis[x]=1;
	
	for(auto i:g->adj[x])
	DFT(g,i,vis);
	
}
int CountTrees(Graph* g)
{
	int res=0;
	
	vector<bool> vis(g->V);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	{
		res++;
		DFT(g,i,vis);
	}
	
	return res;
}
signed main()
{
	int V=5;
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 3, 4);
	
	cout<<CountTrees(g)<<endl;
	
	return 0;
}
