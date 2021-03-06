#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	int **adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new int*[V];
	for(int i=0;i<V;i++)
	{
		g->adj[i]=new int[V];
		memset(g->adj[i],0,sizeof(int)*V);
	}
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	g->adj[u][v]=w;
	g->adj[v][u]=w;
}
void DijkstraSPT(Graph *g)
{
	vector<int> dist(g->V,INT_MAX);
	dist[0]=0;
	vector<bool> vis(g->V);
	vector<int> parent(g->V);
	
	for(int i=1;i<g->V;i++)
	{
		int mn=INT_MAX,ind;
		for(int i=0;i<g->V;i++)
		if(!vis[i] && mn > dist[i])
		{
			mn=dist[i];
			ind=i;
		}
		
		vis[ind]=true;
		
		for(int i=0;i<g->V;i++)
	    if(g->adj[ind][i] && !vis[i] && dist[i] > dist[ind]+g->adj[ind][i])
	    {
	    	dist[i]=dist[ind]+g->adj[ind][i];
	    	parent[i]=ind;
		}
	}
	for(int i=1;i<g->V;i++)
	{
		cout<<"0 -> "<<i<<" --- "<<dist[i]<<"      ";
		
		int j=i;
		stack<int> st;
		st.push(j);
		while(j!=0)
		st.push(parent[j]),j=parent[j];
		
		while(st.size())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}
}
signed main()
{
	int V=9;
	
	Graph* g=CreateGraph(V);
	
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
	
	DijkstraSPT(g);
	
	return 0;
}
