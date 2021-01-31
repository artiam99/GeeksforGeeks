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
Graph* CreateGraph(int V,int E)
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
bool DFS(Graph* g,int u,int &wt,int k,vector<bool> &vis,vector<pair<int,int>> &path)
{
	vis[u]=true;
	path.push_back({u,wt});
	if(wt>=k)
	{
		for(auto i:path)
		cout<<i.first<<" "<<i.second<<endl;
		cout<<endl;
		return true;
	}
	
	
	for(auto i:g->adj[u])
	if(!vis[i.first])
	{
		wt+=i.second;
		if(DFS(g,i.first,wt,k,vis,path))
		return true;
		wt-=i.second;
	}
	path.pop_back();
	vis[u]=false;
	return false;
}
void PathofLengthK(Graph *g,int src,int k)
{
	vector<bool> vis(g->V);
	vector<pair<int,int>> path;
	int wt=0;
	
	if(DFS(g,src,wt,k,vis,path))
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}
signed main()
{
	int V=9,E=14;
	
	Graph* g=CreateGraph(V,E);
	
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
	
	int src=0,k=58;
	
	PathofLengthK(g,src,k);
	
	return 0;
}
