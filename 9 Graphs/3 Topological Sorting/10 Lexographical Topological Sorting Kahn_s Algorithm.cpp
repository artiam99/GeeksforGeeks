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
	int *indegree;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	g->indegree=new int[V];
	memset(g->indegree,0,sizeof(int)*V);
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
	
	g->indegree[v]++;
}
void TopoSort(Graph* g)
{
	set<int> s;
	
	for(int i=0;i<g->V;i++)
	if(!g->indegree[i])
	s.insert(i);
	
	vector<int> topo;
	
	while(s.size())
	{
		int u=*(s.begin());
		s.erase(u);
		
		topo.push_back(u);
		
		for(auto i:g->adj[u])
		{
			g->indegree[i]--;
			
			if(!g->indegree[i])
			s.insert(i);
		}
	}
	
	if(topo.size()!=g->V)
	cout<<"TopoLogical Sorting is not Possible . Cycle Found ."<<endl;
	
	else
	{
		for(auto i:topo)
		cout<<i+1<<" ";
		cout<<endl;
	}
	
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,1,0);
	addEdge(g,2,0);
	addEdge(g,3,2);
	addEdge(g,4,1);
	
	TopoSort(g);
	
	return 0;
}
