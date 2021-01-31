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
	
	vector<int> val;
};
Graph* CreateGraph(int V,vector<int> &val)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	g->val=val;
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
int DFT(Graph* g,int x,vector<bool> &vis,int total,int &mn)
{
	vis[x]=true;
	
	int sum=g->val[x];
	
	for(auto i:g->adj[x])
	{
		if(!vis[i])
		{
			int y=DFT(g,i,vis,total,mn);
			mn=min(mn,abs(total-2*y));
			sum+=y;
		}
	}
	return sum;
}
int FindMinDiff(Graph* g)
{	
	int total=accumulate(g->val.begin(),g->val.end(),0);
	
	int mn=INT_MAX;
	
	vector<bool> vis(g->V,false);
	DFT(g,0,vis,total,mn);
	
	return mn;
}
signed main()
{
	int V=7;
	vector<int> val={4, 2, 1, 6, 3, 5, 2};
	Graph* g=CreateGraph(V,val);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,2,4);
	addEdge(g,2,5);
	addEdge(g,3,6);
	
	cout<<FindMinDiff(g)<<endl;
	
	return 0;
}
