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
void DFT(Graph* g,int u,int v,vector<vector<bool>> &tc)
{
	tc[u][v]=1;
	
	for(auto i:g->adj[v])
	{
		if(!tc[u][i])
		DFT(g,u,i,tc);
	}
}
signed main()
{
	int V=4;
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,2);
	addEdge(g,2,0);
	addEdge(g,2,3);
	
	vector<vector<bool>> tc(V,vector<bool>(V,0));
	
	for(int i=0;i<V;i++)
	DFT(g,i,i,tc);
	
	cout<<"Transitive Closure : \n";
	for(auto i:tc)
	{
		for(auto j:i)
		cout<<j<<" ";
		cout<<endl;
	}
	
	return 0;
}
