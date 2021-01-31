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
	if(parent[x].first != x)
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
void BoruvkasMST(Graph* g)
{
	Edge *edge=g->edge;
	int V=g->V;
	int E=g->E;
	
	int cheapest[V];
	
	pair<int,int> parent[V];
	
	for(int i=0;i<V;i++)
	parent[i]={i,0};
	
	int Dsets=V;
	
	while(Dsets > 1)
	{
		memset(cheapest,-1,sizeof(cheapest));
		
		for(int i=0;i<E;i++)
		{
			int set1=Find(parent,edge[i].src);
			int set2=Find(parent,edge[i].dest);
			
			if(set1==set2)
			continue;
			
			if(cheapest[set1] == -1 || edge[cheapest[set1]].wt > edge[i].wt)
			cheapest[set1]=i;
			
			if(cheapest[set2] == -1 || edge[cheapest[set2]].wt > edge[i].wt)
			cheapest[set2]=i;
		}
		
		for(int i=0;i<V;i++)
		{
			if(cheapest[i]!=-1)
			{
				int set1=Find(parent,edge[cheapest[i]].src);
				int set2=Find(parent,edge[cheapest[i]].dest);
				
				if(set1==set2)
				continue;
				
				Union(parent,set1,set2);
				
				cout<<edge[cheapest[i]].src<<" "<<edge[cheapest[i]].dest<<" -> "<<edge[cheapest[i]].wt<<endl;
				
				Dsets--;
			}
		}
	}
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
	
	BoruvkasMST(g);
	
	return 0;
}
