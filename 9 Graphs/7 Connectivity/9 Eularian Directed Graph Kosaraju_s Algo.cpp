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
void DFS(Graph* g,int u,vector<int> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis);
}
Graph* Transpose(Graph* g,vector<int> &in)
{
	Graph* gt=new Graph;
	
	gt->V=g->V;
	
	gt->adj=new vector<int>[g->V];
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		{
			gt->adj[j].push_back(i);
			in[j]++;
		}
	}
	return gt;
}
bool isStronglyConnected(Graph* g,vector<int> &in)
{
	vector<int> vis(g->V);
	
	int u=0;
	for(;u<g->V;u++)
	if(g->adj[u].size())
	break;
	
	DFS(g,u,vis);
	
	for(int i=0;i<g->V;i++)
	if(g->adj[i].size() && !vis[i])
	return false;
	
	Graph* gt=Transpose(g,in);
	
	for(int i=0;i<g->V;i++)
	vis[i]=false;
	
	DFS(gt,u,vis);
	
	for(int i=0;i<g->V;i++)
	if(g->adj[i].size() && !vis[i])
	return false;
	
	return true;
}
bool isEulerian(Graph* g)
{
	vector<int> in(g->V);
	
	if(!isStronglyConnected(g,in))
	return false;
	
	for(int i=0;i<g->V;i++)
	if(g->adj[i].size() != in[i])
	return false;
	
	return true;
}
signed main()
{
    Graph *g=CreateGraph(5);
    addEdge(g, 1, 0);
    addEdge(g, 0, 2);
    addEdge(g, 2, 1);
    addEdge(g, 0, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 0);
    
    if(isEulerian(g))
    cout<<"Eulerian"<<endl;
    else
    cout<<"Not Eulerian"<<endl;
	
	return 0;
}
