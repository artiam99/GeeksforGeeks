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
	u--,v--;
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,int p,vector<int> &color,vector<int> &parent,vector<int> &mark,int &cnt)
{
	if(color[u] == 1)
	return;
	
	if(color[u] == 0)
	{
		cnt++;
		
		mark[p]=cnt;
		int curr=p;
		while(curr != u)
		{
			curr=parent[curr];
			mark[curr]=cnt;
		}
		return;
	}
	parent[u]=p;
	color[u]=0;
	
	for(auto i:g->adj[u])
	if(i!=p)
	DFS(g,i,u,color,parent,mark,cnt);
	
	color[u]=1;
}
void PrintAllCycles(Graph* g)
{
	vector<int> color(g->V,-1);
	vector<int> parent(g->V);
	vector<int> mark(g->V,-1);
	int cnt=0;
	
	for(int i=0;i<g->V;i++)
	if(color[i]==-1)
	DFS(g,0,-1,color,parent,mark,cnt);
	
	vector<int> cycle[cnt];
	
	for(int i=0;i<g->V;i++)
	if(mark[i]!=-1)
	cycle[mark[i]-1].push_back(i);
	
	for(int i=0;i<cnt;i++)
	{
		cout<<"Cycle "<<i+1<<" : ";
		for(auto j:cycle[i])
		cout<<j+1<<" ";
		cout<<endl<<endl;;
	}
}
signed main()
{
	int V=9;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g, 1, 2); 
    addEdge(g, 1, 3); 
    addEdge(g, 1, 4); 
    addEdge(g, 2, 3); 
    addEdge(g, 4, 9);
	addEdge(g, 1, 9); 
    addEdge(g, 5, 6); 
    addEdge(g, 5, 7); 
    addEdge(g, 5, 8); 
    addEdge(g, 6, 7); 
    addEdge(g, 8, 7); 
	addEdge(g, 1, 5); 

	
	PrintAllCycles(g);
	
	return 0;
}
