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
void PrintGraph(Graph* g)
{
	for(int i=0;i<g->V;i++)
	{
		if(g->adj[i].size())
		{
			cout<<"[ "<<i<<" ]";
			
			for(auto j:g->adj[i])
			if(g->adj[j].size())
			cout<<" -> "<<j;
			
			cout<<endl<<endl;
		}
	}
}
void findKCore(Graph* g,int k)
{
	vector<int> size(g->V);
	vector<bool> removed(g->V);
	
	
	for(int i=0;i<g->V;i++)
	size[i]=g->adj[i].size();
	
	
	while(1)
	{
		bool flag=1;
		
		for(int i=0;i<g->V;i++)
		if(size[i]<k && g->adj[i].size())
		{
			flag=0;
			break;
		}
		
		if(flag)
		break;
		
		for(int i=0;i<g->V;i++)
		{
			if(size[i]<k && g->adj[i].size())
			{
				for(auto j:g->adj[i])
				size[j]--;
				
				g->adj[i].clear();
			}
		}
	}
}
signed main()
{
	int V1=9;
	Graph* g1=CreateGraph(V1);
	
    addEdge(g1,0, 1);
    addEdge(g1,0, 2);
    addEdge(g1,1, 2);
    addEdge(g1,1, 5);
    addEdge(g1,2, 3);
    addEdge(g1,2, 4);
    addEdge(g1,2, 5);
    addEdge(g1,2, 6);
    addEdge(g1,3, 4);
    addEdge(g1,3, 6);
    addEdge(g1,3, 7);
    addEdge(g1,4, 6);
    addEdge(g1,4, 7);
    addEdge(g1,5, 6);
    addEdge(g1,5, 8);
    addEdge(g1,6, 7);
    addEdge(g1,6, 8);
	
	int k=3;
	
	findKCore(g1,k);
	
	PrintGraph(g1);
	
	return 0;
}
