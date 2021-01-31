#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	unordered_set<int> *adj;
};

Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new unordered_set<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].insert(v);
	
	g->adj[v].insert(u);
}
void PrintGraph(Graph* g)
{
	for(int i=0;i<g->V;i++)
	{
		cout<<i;
		
		for(auto j=g->adj[i].begin();j!=g->adj[i].end();j++)
		cout<<"->"<<*j;
		
		cout<<endl;
	}
	cout<<endl;
}
void SearchEdge(Graph* g,int u,int v)
{
	if(g->adj[u].find(v)==g->adj[u].end())
	cout<<"Edge from "<<u<<" to "<<v<<" not found"<<endl;
	
	else
	cout<<"Edge from "<<u<<" to "<<v<<" found"<<endl;
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);	

	PrintGraph(g);
	
	SearchEdge(g,2,1);
	SearchEdge(g,0,3);
	
	return 0;
}
