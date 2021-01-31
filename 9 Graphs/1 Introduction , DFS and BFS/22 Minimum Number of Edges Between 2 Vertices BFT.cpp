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
int MinimumEdges(Graph* g,int u,int v)
{
	queue<int> q;
	
	vector<bool> vis(g->V,false);
	
	q.push(u);
	vis[u]=true;
	
	int cnt=0;
	
	while(q.size())
	{
		int size=q.size();
		
		while(size--)
		{
			int x=q.front(); q.pop();
			
			if(x==v)
			return cnt;
			
			for(auto i:g->adj[x])
			if(!vis[i])
			{
				vis[i]=true;
				q.push(i);
			}
		}
		cnt++;
	}
	return -1;
}
signed main()
{
	int V=9;
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1);
    addEdge(g, 0, 7);
    addEdge(g, 1, 7);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 2, 5);
    addEdge(g, 2, 8);
    addEdge(g, 3, 4);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);
    addEdge(g, 5, 6);
    addEdge(g, 6, 7);
    addEdge(g, 7, 8);
    
	int u = 0,v = 5;
	
	cout<<MinimumEdges(g,u,v)<<endl;
	
	return 0;
}
