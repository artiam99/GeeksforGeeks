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
bool BFS(vector<vector<int>> &rg,int s,int t,vector<int> &parent)
{
	fill(parent.begin(),parent.end(),-1);
	
	vector<bool> vis(rg.size());
	
	queue<int> q;
	q.push(s);
	vis[s]=true;
	
	while(q.size())
	{
		int u=q.front(); q.pop();
		
		for(int i=0;i<rg.size();i++)
		if(!vis[i] && rg[u][i])
		{
			parent[i]=u;
			vis[i]=true;
			q.push(i);
		}
	}
	return vis[t];
}
int DisjointEdgePath(Graph* g,int s,int t)
{
	vector<vector<int>> rg(g->V,vector<int>(g->V,0));
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		rg[i][j]=1;
	}
	
	int mx=0;
	
	vector<int> parent(g->V);
	
	while(BFS(rg,s,t,parent))
	{	
		for(int i=t;i!=s;i=parent[i])
		{
			rg[parent[i]][i]--;
			rg[i][parent[i]]++;
		}
		mx++;
	}
	return mx;
}
signed main()
{
	int V=8;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,1,2);
	addEdge(g,2,3);
	addEdge(g,2,6);
	addEdge(g,3,6);
	addEdge(g,4,2);
	addEdge(g,4,7);
	addEdge(g,5,1);
	addEdge(g,5,4);
	addEdge(g,5,7);
	addEdge(g,6,5);
	addEdge(g,6,7);
	
	int s=0,t=7;
	
	cout<< DisjointEdgePath(g,s,t) <<endl;
	
	return 0;
}
