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
void DFT(Graph* g,int s,int &time,vector<int> &Intime,vector<int> &Outtime,vector<bool> &vis)
{
	Intime[s]=++time;
	
	vis[s]=true;
	
	for(auto i:g->adj[s])
	{
		if(!vis[i])
		DFT(g,i,time,Intime,Outtime,vis);
	}
	
	Outtime[s]=++time;
}
void AnsQueries(Graph* g,vector<pair<int,int>> &Q)
{
	vector<int> Intime(g->V);
	vector<int> Outtime(g->V);
	
	int time=0;
	
	vector<bool> vis(g->V,false);
	
	DFT(g,0,time,Intime,Outtime,vis);
	
	for(auto i:Q)
	{
		if((Intime[i.first]<Intime[i.second] && Outtime[i.first]>Outtime[i.second])||(Intime[i.second]<Intime[i.first] && Outtime[i.second]>Outtime[i.first]))
		cout<<i.first<<" "<<i.second<<" are in Same Path"<<endl;
		else
		cout<<i.first<<" "<<i.second<<" are Not in Same Path"<<endl;
	}
}
signed main()
{
	int V=7;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,1,4);
	addEdge(g,2,5);
	addEdge(g,3,6);
	
	vector<pair<int,int>> Q={{0,5},{1,4},{1,6}};
	
	AnsQueries(g,Q);
	
	return 0;
}
