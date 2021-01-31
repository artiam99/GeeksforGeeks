#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Edge
{
	int src,dest,wt;
};
struct Graph
{
	int V,E;
	Edge *edge;
};
bool comp(Edge x,Edge y)
{
	return x.wt < y.wt;
}
Graph* CreateGraph(int V,int E)
{
	Graph* g=new Graph;
	
	g->V=V;
	g->E=E;
	
	g->edge=new Edge[E];
	
	return g;
}
void addEdge(Graph* g,int i,int u,int v,int w)
{
	g->edge[i].src=u;
	g->edge[i].dest=v;
	g->edge[i].wt=w;
}
int Find(pair<int,int> parent[],int x)
{
	if(parent[x].first!=x)
	parent[x].first=Find(parent,parent[x].first);
	
	return parent[x].first;
}
void Union(pair<int,int> parent[],int sroot,int droot)
{
	if(parent[sroot].second > parent[droot].second)
	parent[droot].first=sroot;
	
	else if(parent[sroot].second < parent[droot].second)
	parent[sroot].first=droot;
	
	else
	{
		parent[droot].first=sroot;
		parent[sroot].second++;
	}
}
void PrintKruskalsTree(Graph* g)
{
	sort(g->edge , g->edge + g->E , comp);
	
	pair<int,int> parent[g->V];
	
	for(int i=0;i<g->V;i++)
	parent[i]={i,0};
	
	vector<Edge> res;
	
	for(int i=0;i<g->E;i++)
	{
		int sroot=Find(parent,g->edge[i].src);
		int droot=Find(parent,g->edge[i].dest);
		
		if(sroot==droot)
		continue;
		
		Union(parent,sroot,droot);
		
		res.push_back(g->edge[i]);
	}
	
	for(auto i:res)
	cout<<i.src<<" "<<i.dest<<" -> "<<i.wt<<endl;
}
signed main()
{
	int V=9,E=14;
	
	Graph* g=CreateGraph(V,E);
	
	addEdge(g,0,0,1,4);
	addEdge(g,1,0,7,8);
	addEdge(g,2,1,2,8);
	addEdge(g,3,1,7,11);
	addEdge(g,4,7,8,7);
	addEdge(g,5,7,6,1);
	addEdge(g,6,2,8,2);
	addEdge(g,7,6,8,6);
	addEdge(g,8,6,5,2);
	addEdge(g,9,2,5,4);
	addEdge(g,10,2,3,7);
	addEdge(g,11,3,5,14);
	addEdge(g,12,3,4,9);
	addEdge(g,13,4,5,10);
	
	PrintKruskalsTree(g);
	
	return 0;
}
