#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V,E;
	pair<int,int> *edge;
};
Graph* CreateGraph(int V,int E)
{
	Graph* g=new Graph;
	
	g->V=V;
	g->E=E;
	
	g->edge=new pair<int,int>[E];
	
	return g;
}
void addEdge(Graph* g,int i,int u,int v)
{
	g->edge[i].first=u;
	g->edge[i].second=v;
}
bool DetectCycle(Graph* g)
{
	vector<int> parent(g->E,-1);
	
	int cnt=0;
	
	for(int i=0;i<g->E;i++)
	{
		int u=g->edge[i].first;
		int v=g->edge[i].second;
		
		while(parent[u]>=0)
		u=parent[u];
		
		while(parent[v]>=0)
		v=parent[v];
		
		if(u==v)
		return true;
		
		if(u<=v)
		{
			parent[u]+=parent[v];
			parent[v]=u;
		}
		else
		{
			parent[v]+=parent[u];
			parent[u]=v;
		}
	}

	return false;
}
signed main()
{
	int V=8,E=9;
	
	Graph* g=CreateGraph(V,E);
	
	addEdge(g,0,0,1);
	addEdge(g,1,1,2);
	addEdge(g,2,2,3);
	addEdge(g,3,3,0);
	addEdge(g,4,1,4);
	addEdge(g,5,4,5);
	addEdge(g,6,5,6);
	addEdge(g,7,6,7);
	addEdge(g,8,4,7);
	
	if(DetectCycle(g))
	cout<<"Cycle Present"<<endl;
	else
	cout<<"Cycle Not Present"<<endl;
	
	return 0;
}
