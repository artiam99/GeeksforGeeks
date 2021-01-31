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
void store(int s,int u,Graph* g,vector<int> rank[],vector<bool> &vis)
{
	vis[u]=true;
	
	rank[u].push_back(s);
	
	for(auto i:g->adj[u])
	if(!vis[i])
	store(s,i,g,rank,vis);
	
}
bool check(vector<int> rank[],int u,vector<bool> &vis)
{
	for(auto i:rank[u])
	if(!vis[i])
	return false;
	return true;
}
void PrintAll(Graph* g,vector<int> rank[],vector<bool> &vis,vector<int> &a)
{
	bool flag=0;
	for(int i=0;i<g->V;i++)
	{
		if(!vis[i] && check(rank,i,vis))
		{
			a.push_back(i);
			vis[i]=true;
			
			PrintAll(g,rank,vis,a);
			
			a.pop_back();
			vis[i]=false;
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
void PrintALLTopoSort(Graph* g)
{
	vector<bool> vis(g->V,false);
	
	vector<int> rank[g->V];
	
	for(int k=0;k<g->V;k++)
	{
		for(int i=0;i<g->V;i++)
		vis[i]=false;
		
		for(auto i:g->adj[k])
		store(k,i,g,rank,vis);
		
	}
	
	for(int i=0;i<g->V;i++)
	vis[i]=false;
	
	vector<int> a;
	
	PrintAll(g,rank,vis,a);
	
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
	
	PrintALLTopoSort(g);
	
	return 0;
}
