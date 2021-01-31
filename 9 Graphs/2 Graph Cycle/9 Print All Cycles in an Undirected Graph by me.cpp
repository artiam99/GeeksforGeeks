#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	vector<bool> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<bool>[V];
	
	for(int i=0;i<V;i++)
	g->adj[i]=vector<bool>(V,0);
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	u--,v--;
	g->adj[u][v]=g->adj[v][u]=true;
}
void DFS(Graph* g,int vert,int start,int parent,vector<bool> &vis,vector<int> &path,set<int> &s)
{
	vis[vert]=true;
	path.push_back(vert);
	
	if(g->adj[vert][start] && start!=parent)
	{
		s.insert(vert);
		vis[vert]=false;
		
		for(auto i:path)
		cout<<i+1<<" ";
		cout<<endl;
		
		path.pop_back();
		
		return;
	}
	
	for(int i=0;i<g->V;i++)
	if(g->adj[vert][i] && s.find(i)==s.end() && !vis[i])
	DFS(g,i,start,vert,vis,path,s);
	
	vis[vert]=false;
	
	path.pop_back();
}
void PrintAllCycles(Graph* g)
{
	vector<bool> vis(g->V,false);
	vector<int> path;
	
	for(int i=0;i<g->V;i++)
	{
		set<int> s;
		DFS(g,i,i,-1,vis,path,s);
		vis[i]=true;
	}
	
}
signed main()
{
	int V=13;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,1,2);
	addEdge(g,2,3);
	addEdge(g,3,4);
	addEdge(g,3,5);
	addEdge(g,4,6);
	addEdge(g,4,7);
	addEdge(g,7,8);
	addEdge(g,5,6);
	addEdge(g,5,9);
	addEdge(g,6,10);
	addEdge(g,10,11);
	addEdge(g,11,12);
	addEdge(g,11,13);
	addEdge(g,12,13);
	
	PrintAllCycles(g);
	
	return 0;
}
