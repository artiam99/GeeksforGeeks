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
bool DFS(Graph* g,int u,int x,int limit)
{
	if(u==x)
	return true;
	
	if(limit==0)
	return false;
	
	for(auto i:g->adj[u])
	{
		if(DFS(g,i,x,limit-1))
		return true;
	}
	return false;
}
bool IDDFS(Graph* g,int src,int tar,int maxdepth)
{
	for(int i=0;i<=maxdepth;i++)
	if(DFS(g,src,tar,i))
	return true;
	return false;
}
signed main()
{
	int V=7;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,3);
	addEdge(g,1,4);
	addEdge(g,2,5);
	addEdge(g,2,6);
	
	int src=0,tar=6,maxdepth=3;
	if(IDDFS(g,src,tar,maxdepth))
	cout<<tar<<" is found from "<<src<<endl;
	else
	cout<<tar<<" Not Found"<<endl;
	
	return 0;
}
