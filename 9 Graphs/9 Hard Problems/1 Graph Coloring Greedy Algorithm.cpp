#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
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
void GreedyColoring(Graph* g)
{
	vector<int> res(g->V,-1);
	res[0]=0;
	
	vector<bool> available(g->V);
	
	for(int i=1;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		if(res[j] != -1)
		available[res[j]]=true;
		
		for(int j=0;j<g->V;j++)
		if(!available[j])
		{
			res[i]=j;
			break;
		}
		
		for(auto j:g->adj[i])
		if(res[j] != -1)
		available[res[j]]=false;
	}
	
	for(int i=0;i<g->V;i++)
	cout<<"Color of "<<i<<" is "<<res[i]<<endl;
}
signed main()
{
	Graph *g1=CreateGraph(5);
    
	addEdge(g1, 0, 1);
    addEdge(g1, 0, 2);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);
    
	cout << "Coloring of graph 1" <<endl<<endl;
    
	GreedyColoring(g1);
  
    Graph *g2=CreateGraph(5);
    
    addEdge(g2, 0, 1);
    addEdge(g2, 0, 2);
    addEdge(g2, 1, 2);
    addEdge(g2, 1, 4);
    addEdge(g2, 2, 4);
    addEdge(g2, 4, 3);
    
    cout << "\nColoring of graph 2" <<endl<<endl;
    
	GreedyColoring(g2);
  
    return 0;
}
