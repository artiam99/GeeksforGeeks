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
bool DFS(Graph* g,int u,vector<bool> &vis,vector<bool> &recstk)
{
	vis[u]=true;
	recstk[u]=true;
	
	for(auto i:g->adj[u])
	{
		if(!vis[i] && DFS(g,i,vis,recstk))
		return true;
		
		else if(recstk[i])
		return true;
	}
	
	recstk[u]=false;
	
	return false;
}
bool DetectCycle(Graph* g)
{
	vector<bool> vis(g->V,false);
	vector<bool> recstk(g->V,false);
	
	for(int i=0;i<g->V;i++)
	if(DFS(g,i,vis,recstk))
	return true;
	
	return false;
}
signed main()
{
	int V=4;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,2);
	addEdge(g,1,0);
	addEdge(g,1,2);
	addEdge(g,2,0);
	addEdge(g,2,3);
	addEdge(g,3,3);
	
	if(DetectCycle(g))
	cout<<"Cycle Present"<<endl;
	else
	cout<<"Cycle Not Present"<<endl;
	
	return 0;
}
