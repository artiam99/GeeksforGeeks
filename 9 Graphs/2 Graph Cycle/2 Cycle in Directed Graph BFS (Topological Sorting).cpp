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
bool DetectCycle(Graph* g)
{
	vector<int> indegree(g->V);
	
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		indegree[j]++;
	}
	
	queue<int> q;
	
	for(int i=0;i<g->V;i++)
	if(!indegree[i])
	q.push(i);
	
	int cnt=0;
	
	while(q.size())
	{
		int u=q.front(); 
		q.pop();
		
		for(auto i:g->adj[u])
		{
			if(--indegree[i]==0)
			q.push(i);
		}
		cnt++;
	}
	return (cnt!=g->V);
}
signed main()
{
	int V=4;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,2);
	addEdge(g,1,0);
	addEdge(g,1,2);
	addEdge(g,2,0);
	addEdge(g,2,3);
	addEdge(g,3,3);
	
	if(DetectCycle(g))
	cout<<"Cycle Present"<<endl;
	else
	cout<<"Cycle Not Present"<<endl;
	
	return 0;
}
