#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int V;
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V*2];
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	if(w==2)
	{
		g->adj[u].push_back(v+g->V);
		g->adj[v+g->V].push_back(v);
	}
	else
	g->adj[u].push_back(v);
}
void ShortestPath(Graph* g,int src,int dest)
{
	vector<int> vis(2*g->V);
	
	vector<int> parent(2*g->V);
	
	queue<int> q;
	q.push(src);
	
	parent[src]=-1;
	vis[src]=true;
	
	while(q.size())
	{
		int u=q.front(); q.pop();
		
		if(u==dest)
		{
			stack<int> st;
			st.push(u);
			while(parent[u]!=-1)
			{
				if(parent[u]<g->V)
				st.push(parent[u]);
				
				u=parent[u];
			}
			
			while(st.size())
			{
				cout<<st.top()<<" ";
				st.pop();
			}
			cout<<endl;
			
			return;
		}
		
		for(auto i:g->adj[u])
		if(!vis[i])
		{
			vis[i]=true;
			parent[i]=u;
			q.push(i);
		}
	}
	cout<<"No Path Found"<<endl;
}
signed main()
{
	int V=4;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 1, 2); 
    addEdge(g, 0, 2, 2); 
    addEdge(g, 1, 2, 1); 
    addEdge(g, 1, 3, 1); 
    addEdge(g, 2, 0, 1); 
    addEdge(g, 2, 3, 2); 
    addEdge(g, 3, 3, 2);
	
	int src=0,dest=3;
	ShortestPath(g,src,dest);
	
	return 0;
}
