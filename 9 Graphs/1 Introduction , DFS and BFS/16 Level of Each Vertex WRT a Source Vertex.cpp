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
void Levels(Graph* g,int s)
{
	queue<int> q;
	
	vector<int> lvl(g->V,0);
	
	q.push(s);
	lvl[s]=1;
	
	while(q.size())
	{
		int x=q.front();
		q.pop();
		
		for(auto i:g->adj[x])
		if(!lvl[i])
		{
			lvl[i]=lvl[x]+1;
			q.push(i);
		}
	}
	
	cout<<"Nodes    Level"<<endl;
	for(int i=0;i<g->V;i++)
	cout<<  i   <<"-------> "<<lvl[i]-1<<endl;
}
signed main()
{
	int V=8;
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 1, 3);
	addEdge(g, 1, 4);
	addEdge(g, 1, 5);
	addEdge(g, 2, 5);
	addEdge(g, 2, 6);
	addEdge(g, 6, 7);
	
	Levels(g,0);
	
	return 0;
}
