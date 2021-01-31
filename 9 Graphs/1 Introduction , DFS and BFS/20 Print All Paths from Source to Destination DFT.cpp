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
void DFT(Graph* g,int s,int d,vector<bool> &vis,vector<int> &paths)
{
	if(s==d)
	{
		for(auto i:paths)
		cout<<i<<" ";
		cout<<d<<endl;
		return;
	}
	vis[s]=1;
	paths.push_back(s);
	
	for(auto i:g->adj[s])
	if(!vis[i])
	DFT(g,i,d,vis,paths);
	
	vis[s]=0;
	paths.pop_back();
}
void PrintallPaths(Graph* g,int s,int d)
{
	vector<int> paths;
	vector<bool> vis(g->V,false);
	
	DFT(g,s,d,vis,paths);
}
signed main()
{
	int V=4;
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,3);
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,3);
	addEdge(g,2,0);
	addEdge(g,2,1);
	
	int s=2,d=3;
	
	PrintallPaths(g,s,d);
	
	return 0;
}
