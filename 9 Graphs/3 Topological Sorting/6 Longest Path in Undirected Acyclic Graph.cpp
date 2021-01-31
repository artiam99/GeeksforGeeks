#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	vector<pair<int,int>> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<pair<int,int>>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	u--,v--;
	g->adj[u].push_back({v,w});
	g->adj[v].push_back({u,w});
}
int DFS(Graph* g,int u,int w,int &total,vector<bool> &vis)
{
	vis[u]=true;
	
	int max1=0,max2=0;
	
	for(auto i:g->adj[u])
	{
		if(vis[i.first])
		continue;
		
		int x=DFS(g,i.first,i.second,total,vis);
		
		if(x > max1)
		{
			max2=max1;
			max1=x;
		}
		else
		max2=max(max2,x);
	}
	
	total= max(total,max1+max2);
	
	return max1+w;
}
int WeightDiameter(Graph* g)
{
	
	int total=0;
	
	vector<bool> vis(g->V,false);
	
	DFS(g,0,0,total,vis);
	
	return total;
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,1,2,3);
	addEdge(g,2,3,4);
	addEdge(g,2,6,2);
	addEdge(g,6,4,6);
	addEdge(g,6,5,5);
	
	cout<<WeightDiameter(g)<<endl;
	
	return 0;
}
