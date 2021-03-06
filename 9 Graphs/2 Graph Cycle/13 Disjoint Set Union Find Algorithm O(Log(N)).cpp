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
int Find(vector<pair<int,int>> &parent,int x)
{
	if(parent[x].first!=x)
	parent[x].first = Find(parent,parent[x].first);
	
	return parent[x].first;
}
void Union(vector<pair<int,int>> &parent,int uroot,int vroot)
{
	if( parent[uroot].second > parent[vroot].second)
	parent[vroot].first=uroot;
	
	else if(parent[uroot].second < parent[vroot].second)
	parent[uroot].first=vroot;
	
	else
	{
		parent[vroot].first=uroot;
		parent[uroot].second++;
	}
}
bool DetectCycle(Graph* g)
{
	vector<pair<int,int>> parent(g->V);
	
	for(int i=0;i<g->V;i++)
	parent[i]={i,0};// ( parent , rank )
	
	int cnt=0;
	
	for(int i=0;i<g->E;i++)
	{
		int uroot=Find(parent,g->edge[i].first);
		int vroot=Find(parent,g->edge[i].second);
		
		if(uroot==vroot)
		return true;
		
		Union(parent,uroot,vroot);
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
