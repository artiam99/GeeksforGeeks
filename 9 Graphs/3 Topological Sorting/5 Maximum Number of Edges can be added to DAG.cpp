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
void topo(Graph* g,int u,vector<bool> &vis,stack<int> &st)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	topo(g,i,vis,st);
	
	st.push(u);
}
int MaximumEdges(Graph* g)
{
	vector<bool> vis(g->V);
	stack<int> st;
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	topo(g,i,vis,st);
	
	vector<int> a;
	
	while(st.size())
	{
		a.push_back(st.top());
		st.pop();
	}
	
	int cnt=0;
	
	for(int i=0;i<g->V;i++)
	cnt+=(g->V-i-1) - g->adj[i].size();
	
	return cnt;
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
	
	cout<<MaximumEdges(g)<<endl;
	
	return 0;
}
