#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
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
	g->adj[v].push_back(u);
}
int Find(vector<pair<int,int>> &parent,int x)
{
	if(parent[x].first != x)
	parent[x].first = Find(parent,parent[x].first);
	return parent[x].first;
}
void Union(vector<pair<int,int>> &parent,int sroot,int droot)
{
	if(parent[sroot].second > parent[droot].second)
	parent[droot].first = sroot;
	
	else if(parent[sroot].second < parent[droot].second)
	parent[sroot].first = droot;
	
	else
	{
		parent[droot].first = sroot;
		parent[sroot].second++;
	}
}
int Minimum_Cut(Graph* g)
{
	srand(time(NULL));
	
	vector<pair<int,int>> parent(g->V);
	
	for(int i=0;i<g->V;i++)
	parent[i]={i,0};
	
	int vtx = g->V;
	
	vector<pair<int,int>> edge;
	set<pair<int,int>> st;
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		{
			if(st.find({j,i}) == st.end())
			{
				edge.push_back({i,j});
				st.insert({i,j});
			}
		}
	}
	
	while(vtx > 2)
	{
		int ind = rand() % edge.size();
		
		int sroot = Find(parent,edge[ind].first);
		int droot = Find(parent,edge[ind].second);
		
		if( sroot == droot)
		continue;
		
		Union(parent,sroot,droot);
		
		vtx--;
	}
	
	int mincut=0;
	
	for(int i=0;i<edge.size();i++)
	{
		int sroot = Find(parent,edge[i].first);
		int droot = Find(parent,edge[i].second);
		
		if(sroot != droot)
		mincut++;
	}
	return mincut;
}
signed main()
{
	int V=4;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,1,3);
	addEdge(g,2,3);
	
	cout<< Minimum_Cut(g) <<endl;
	
	return 0;
}
