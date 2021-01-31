#include<bits/stdc++.h>
using namespace std;
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
void TransitiveClosure(Graph* g)
{
	vector<vector<bool>> tc(g->V,vector<bool>(g->V,false));
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		tc[i][j]=true;
	}
	
	for(int k=0;k<g->V;k++)
	{
		for(int i=0;i<g->V;i++)
		{
			for(int j=0;j<g->V;j++)
			tc[i][j] = ( tc[i][j] || (tc[i][k] && tc[k][j]) );
		}
	}
	
	for(auto i:tc)
	{
		for(auto j:i)
		cout<<j<<" ";
		cout<<endl;
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
	addEdge(g,3,3);
	
	TransitiveClosure(g);
	
	return 0;
}
