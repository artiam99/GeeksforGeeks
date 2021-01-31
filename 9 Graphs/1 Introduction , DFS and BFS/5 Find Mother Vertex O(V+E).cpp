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
void DFT(Graph* g,int x,vector<bool> &present)
{
	if(present[x])
	return;
	
	present[x]=true;
	
	for(auto i:g->adj[x])
	DFT(g,i,present);
}
int FindMother(Graph* g)
{
	vector<bool> present(g->V,false);
	
	int v=0;
	
	for(int i=0;i<g->V;i++)
	{
		if(present[i])
		continue;
		
		DFT(g,i,present);
		
		v=i;//last visited Node
	}
	
	fill(present.begin(),present.end(),false);
	
	DFT(g,v,present);
	
	for(auto i:present)
	if(!i)
	return -1;
	return v;
}
signed main()
{
	int V=7;
	
	Graph* g=CreateGraph(V);
	 
    addEdge(g,0, 1);
    addEdge(g,0, 2);
    addEdge(g,1, 3);
    addEdge(g,4, 1);
    addEdge(g,6, 4);
    addEdge(g,5, 6);
    addEdge(g,5, 2);
    addEdge(g,6, 0);
    
    cout<<FindMother(g);
	
	return 0;
}
