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
	queue<int> q;
	
	for(int i=0;i<g->V;i++)
	if(!g->indegree[i])
	q.push(i);
	
	vector<int> topo;
	
	while(q.size())
	{
		int u=q.front();
		q.pop();
		
		topo.push_back(u);
		
		for(auto i:g->adj[u])
		{
			g->indegree[i]--;
			
			if(!g->indegree[i])
			q.push(i);
		}
	}
	
	if(topo.size()!=g->V)
	cout<<"TopoLogical Sorting is not Possible . Cycle Found ."<<endl;
	
	else
	{
		for(auto i:topo)
		cout<<i<<" ";
		cout<<endl;
	}
	
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,2,3);
	addEdge(g,3,1);
	addEdge(g,4,0);
	addEdge(g,4,1);
	addEdge(g,5,0);
	addEdge(g,5,2);
	
	TopoSort(g);
	
	return 0;
}
