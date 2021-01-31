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
bool DFS(Graph* g,int u,vector<bool> &vis,int v)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	{
		if(!vis[i] && DFS(g,i,vis,u))
		return true;
		
		else if(i!=v)
		return true;
	}
	
	return false;
}
bool DetectCycle(Graph* g)
{
	vector<bool> vis(g->V,false);
	
	for(int i=0;i<g->V;i++)
	if(DFS(g,i,vis,-1))
	return true;
	
	return false;
}
signed main()
{
	int V=4;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,2);
	addEdge(g,2,3);
	
	if(DetectCycle(g))
	cout<<"Cycle Present"<<endl;
	else
	cout<<"Cycle Not Present"<<endl;
	
	return 0;
}
