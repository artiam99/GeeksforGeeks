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
void DFS1(Graph* g,int u,vector<bool> &vis,stack<int> &st)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS1(g,i,vis,st);
	
	st.push(u);
}
void DFS2(Graph* g,int u,vector<bool> &vis)
{
	cout<<u<<" ";
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS2(g,i,vis);
}
Graph* Transpose(Graph* g)// There can't be any cycle between two Strongly Connected Components...after changind directions No connections are there between previos visited component to
{                        //  next visited components and points in previous components comes first in the stack so we don't go to the next visited component 
	Graph* g1=new Graph;
	
	g1->V=g->V;
	
	g1->adj=new vector<int>[g->V];
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		g1->adj[j].push_back(i);
	}
	
	return g1;
}
void SCC(Graph* g)
{
	stack<int> st;
	
	vector<bool> vis(g->V);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	DFS1(g,i,vis,st);
	
	Graph* g1=Transpose(g);
	
	for(int i=0;i<g->V;i++)
	vis[i]=false;
	
	while(st.size())
	{
		if(!vis[st.top()])
		{
			DFS2(g1,st.top(),vis);
			
			cout<<endl<<endl;
		}
		
		st.pop();
	}
}
signed main()
{
    Graph *g=CreateGraph(5);
    
    addEdge(g, 1, 0);
    addEdge(g, 0, 2);
    addEdge(g, 2, 1);
    addEdge(g, 0, 3);
    addEdge(g, 3, 4);
	
	SCC(g);
	
	return 0;
}
