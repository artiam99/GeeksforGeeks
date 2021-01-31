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
}
Graph* makeTranspose(Graph* g)
{
	Graph* tg=CreateGraph(g->V);
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		addEdge(tg,j,i);
	}
	
	return tg;
}
void printGraph(Graph* g)
{
	for(int i=0;i<g->V;i++)
	{
		cout<<i<<"---> ";
		for(auto j:g->adj[i])
		cout<<j<<" ";
		
		cout<<endl;
	}
}
signed main()
{
	int V=5;
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 0, 3);
    addEdge(g, 2, 0);
    addEdge(g, 3, 2);
    addEdge(g, 4, 1);
    addEdge(g, 4, 3);
    
    Graph* tg=makeTranspose(g);
    
    printGraph(tg);
	
	return 0;
}
