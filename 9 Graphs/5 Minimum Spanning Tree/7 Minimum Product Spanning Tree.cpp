#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V,E;
	int **adj;
};
struct comp
{
	bool operator () (pair<double,int> x,pair<double,int> y)
	{
		return x.first>y.first;
	}
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
void MPST(Graph *g)
{
	double logadj[g->V][g->V];
	
	for(int i=0;i<g->V;i++)
	{
		for(int j=0;j<g->V;j++)
		{
			if(g->adj[i][j])
			logadj[i][j]=(double)log2(g->adj[i][j]);
	
			else
			logadj[i][j]=0.0;
		}
	}
	
	vector<double> key(g->V,INT_MAX);
	key[0]=0.0;
	vector<bool> vis(g->V);
	vector<pair<int,int>> parent(g->V);
	
	priority_queue<pair<double,int>,vector<pair<double,int>>,comp> pq;
	pq.push({0,0});
	
	while(pq.size())
	{
		int u=pq.top().second; pq.pop();
		
		if(!vis[u])
		{
			vis[u]=true;
			
			for(int i=0;i<g->V;i++)
			if(logadj[u][i] && !vis[i] && key[i]>logadj[u][i])
			{
				key[i]=logadj[u][i];
				pq.push({key[i],i});
				parent[i]={u,g->adj[u][i]};
			}
		}
	}
	
	for(int i=1;i<g->V;i++)
	cout<<i<<" "<<parent[i].first<<" -> "<<parent[i].second<<endl;
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1,2);
	addEdge(g,0,3,6);
	addEdge(g,1,2,3);
	addEdge(g,1,3,8);
	addEdge(g,1,4,5);
	addEdge(g,2,4,7);
	addEdge(g,3,4,9);
	
	MPST(g);
	
	return 0;
}
