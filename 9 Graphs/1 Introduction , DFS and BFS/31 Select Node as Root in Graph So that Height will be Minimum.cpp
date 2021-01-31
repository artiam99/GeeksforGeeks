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
void FindRoot(Graph* g)
{
	vector<int> degree(g->V);
	
	for(int i=0;i<g->V;i++)
	degree[i]=g->adj[i].size();
	
	queue<int> q;
	int V=g->V;
	
	for(int i=0;i<g->V;i++)
	if(degree[i]==1)
	q.push(i);
	
	while(V>2 && q.size())
	{
		int x=q.front();
		q.pop();
		V--;
		
		for(auto i:g->adj[x])
		{
			degree[i]--;
			if(degree[i]==1)
			q.push(i);
		}
	}
	
	while(q.size())// There may be cases where 2 ans are there in queue but ans in only one if their initial degrees are same both correct else max degree will be ans
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,2);
	addEdge(g,1,2);
	addEdge(g,2,3);
	addEdge(g,3,4);
	
	FindRoot(g);
	
	return 0;
}
