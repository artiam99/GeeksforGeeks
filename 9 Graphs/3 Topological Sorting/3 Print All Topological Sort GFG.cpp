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
void PrintAll(Graph* g,vector<bool> &vis,vector<int> &a)
{
	bool flag=0;
	
	for(int i=0;i<g->V;i++)
	{
		if(g->indegree[i]==0 && !vis[i])
		{
			a.push_back(i);
			vis[i]=true;
			
			for(auto j:g->adj[i])
			g->indegree[j]--;
			
			PrintAll(g,vis,a);
			
			for(auto j:g->adj[i])
			g->indegree[j]++;
						
			vis[i]=false;
			a.pop_back();
			
			flag=1;
		}
	}
	
	if(!flag)
	{
		for(auto i:a)
		cout<<i<<" ";
		cout<<endl;
	}
}
void PrintAllTopoSort(Graph* g)
{
	vector<int> a;
	vector<bool> vis(g->V,false);
	
	PrintAll(g,vis,a);
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
	
	PrintAllTopoSort(g);
	
	return 0;
}
