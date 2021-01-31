#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Graph
{
	int m,n;
	vector<int> *adj;
};
Graph* CreateGraph(int m,int n)
{
	Graph* g=new Graph;
	
	g->m=m;
	g->n=n;
	
	g->adj=new vector<int>[m+1];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
bool BFS(Graph* g,vector<int> &pairU,vector<int> &pairV,vector<int> &dist)
{
	queue<int> q;
	
	for(int i=1;i<=g->m;i++)
	{
		if(pairU[i]==0)
		{
			dist[i]=0;
			q.push(i);
		}
		else
		dist[i]=INT_MAX;
	}
	
	dist[0]=INT_MAX;
	
	while(q.size())
	{
		int u=q.front(); q.pop();
		
		if(dist[u] < dist[0])
		{
			for(auto i:g->adj[u])
			{
				if(dist[pairV[i]]==INT_MAX)
				{
					dist[pairV[i]] = dist[u] + 1;
					q.push(pairV[i]);
				}
			}
		}
	}
	return (dist[0] != INT_MAX);
}
bool DFS(Graph* g,int u,vector<int> &pairU,vector<int> &pairV,vector<int> &dist)
{
	if(u==0)
	return true;
	
	for(auto i:g->adj[u])
	{
		if(dist[pairV[i]] == dist[u] + 1 && DFS(g,pairV[i],pairU,pairV,dist))
		{
			pairU[u]=i;
			pairV[i]=u;
			
			return true;
		}
	}
	dist[u]=INT_MAX;
	return false;
}
int HopcroftKarp(Graph* g)
{
	vector<int> pairU(g->m+1,0) , pairV(g->n+1,0) , dist(g->m+1);
	
	int cnt=0;
	
	while(BFS(g,pairU,pairV,dist))
	{
		for(int i=1;i<=g->m;i++)
		if(pairU[i]==0 && DFS(g,i,pairU,pairV,dist))
		cnt++;
	}
	return cnt;
}
signed main()
{
	Graph* g=CreateGraph(4,4);
	
	addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 1);
    addEdge(g, 3, 2);
    addEdge(g, 4, 2);
    addEdge(g, 4, 4);
	
	cout<<"Maximum Matching "<< HopcroftKarp(g) <<endl;
		
	return 0;
}
