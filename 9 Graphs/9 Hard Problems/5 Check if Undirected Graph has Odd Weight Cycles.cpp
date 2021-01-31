#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
struct Graph
{
	int V;
	vector<pair<int,int>> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<pair<int,int>>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	u--;v--;
	g->adj[u].push_back({v,w});
	g->adj[v].push_back({u,w});
}
bool isBPTUntill(vector<int> adj[],int src,int V,vector<int> &color)
{
	queue<int> q;
	
	q.push(src);
	color[src]=0;
	
	while(q.size())
	{
		int u=q.front(); q.pop();
		
		for(auto i:adj[u])
		{
			if(color[i] == -1 )
			{
				q.push(i);
				color[i] = 1 - color[u];
			}
			
			else if(color[i] == color[u])
			return false;
		}
	}
	return true;
}
bool isBipartite(vector<int> adj[],int V)
{
	vector<int> color(V,-1);
	
	for(int i=0;i<V;i++)
	if(color[i]==-1 && !isBPTUntill(adj,i,V,color))
	return false;
	
	return true;
}
bool OddWeightCycle(Graph* g)
{
	vector<int> adj[g->V*2];
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		{
			if(j.first > i)
			{
				if(j.second & 1)
				{
					adj[i].push_back(j.first);
					adj[j.first].push_back(i);
				}
				else
				{
					adj[i].push_back(i+g->V);
					adj[i+g->V].push_back(i);
					adj[j.first].push_back(i+g->V);
					adj[i+g->V].push_back(j.first);
				}
			}
		}
	}
	
	return !isBipartite(adj,g->V*2);
}
signed main()
{
	Graph *g=CreateGraph(4);
    
	addEdge(g, 1, 2, 12);
    addEdge(g, 2, 3, 1);
    addEdge(g, 4, 3, 1);
    addEdge(g, 4, 1, 20);
    
	if(OddWeightCycle(g))
	cout<< "Odd Weight Cycles present." <<endl;
	else
	cout<< "No Odd Weight Cycles present." <<endl;
  
    return 0;
}
