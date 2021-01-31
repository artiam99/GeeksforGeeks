#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
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
void VertexCover(Graph* g)
{
	vector<bool> vis(g->V);
	
	for(int i=0;i<g->V;i++)
	{
		if(!vis[i])
		{
			for(auto j:g->adj[i])
			if(!vis[j])
			{
				vis[i]=vis[j]=true;
				break;
			}
		}
	}
	
	for(int i=0;i<g->V;i++)
	if(vis[i])
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	Graph* g=CreateGraph(7);
	
	addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    addEdge(g, 5, 6);
    
    VertexCover(g);
    
    return 0;
}
