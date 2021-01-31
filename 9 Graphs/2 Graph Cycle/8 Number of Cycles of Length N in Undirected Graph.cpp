#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	vector<bool> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<bool>[V];
	
	for(int i=0;i<V;i++)
	g->adj[i]=vector<bool>(V,0);
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u][v]=g->adj[v][u]=true;
}
void DFS(Graph* g,int vert,int start,vector<bool> &vis,int N,int &cnt)
{
	vis[vert]=true;
	
	if(N==0)
	{
		vis[vert]=false;
		
		if(g->adj[vert][start])
		cnt++;
		
		return;
	}
	
	for(int i=0;i<g->V;i++)
	{
		if(g->adj[vert][i] && !vis[i])
		DFS(g,i,start,vis,N-1,cnt);
	}
	
	vis[vert]=false;
}
int CountCycle(Graph* g,int N)
{
	vector<bool> vis(g->V,false);
	int cnt=0;
	
	for(int i=0;i<g->V;i++)
	{
		DFS(g,i,i,vis,N-1,cnt);// vis is working like recursion stack mark 
		
		vis[i]=true;// But after done with one vertex as start we won't visit it again
	}
	
	return cnt/2;
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,3);
	addEdge(g,1,2);
	addEdge(g,1,4);
	addEdge(g,2,3);
	addEdge(g,3,4);
	
	int N=4;
	
	cout<<"There are "<<CountCycle(g,N)<<" of size "<<N<<" in the Graph"<<endl;
	
	return 0;
}
