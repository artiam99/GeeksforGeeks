#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int V;
	list<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new list<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
int DFSCNT(Graph* g,int u,vector<bool> &vis)
{
	int cnt=1;
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(i!=-1 && !vis[i])
	cnt+=DFSCNT(g,i,vis);
	
	return cnt;
}
bool isvalid(Graph* g,int u,int v)
{
	int cnt=0;
	
	for(auto i:g->adj[u])
	if(i!=-1)
	cnt++;
	
	if(cnt==1)
	return true;
	
	vector<bool> vis(g->V);
	int cnt1=DFSCNT(g,u,vis);
	
	list<int>::iterator iu=find(g->adj[u].begin(),g->adj[u].end(),v);
	list<int>::iterator iv=find(g->adj[v].begin(),g->adj[v].end(),u);
	
	*iu=*iv=-1;
	
	for(int i=0;i<g->V;i++)
	vis[i]=false;
	
	int cnt2=DFSCNT(g,u,vis);
	
	addEdge(g,u,v);
	
	return (cnt1 > cnt2) ? false : true;
}
void printUntill(Graph* g,int u)
{
	for(auto i:g->adj[u])
	{
		if(i!=-1 && isvalid(g,u,i))
		{
			int v=i;
			
			cout<<u<<" -- "<<v<<"  ";
			
			list<int>::iterator iu=find(g->adj[u].begin(),g->adj[u].end(),v);
			list<int>::iterator iv=find(g->adj[v].begin(),g->adj[v].end(),u);
			
			*iu=*iv=-1;
			
			printUntill(g,v);
		}
	}
}
void printEulerTour(Graph *g)
{
	int u=0,v;
	
	for(int i=0;i<g->V;i++)
	if(g->adj[i].size() & 1)
	{
		u=i;
		break;
	}
	
	bool flag=0;
	if(u==g->V)
	{
		flag=1;
		
		u=0;
		v=*(g->adj[u].begin());
		
		g->adj[u].remove(v);
		g->adj[v].remove(u);
	}
	
	printUntill(g,u);
	
	if(flag)
	cout<<v<<" -- "<<u;
	
	cout<<endl<<endl;
}
signed main()
{
	Graph *g1=CreateGraph(4);
	addEdge(g1, 0, 1);
	addEdge(g1, 0, 2);
	addEdge(g1, 1, 2);
	addEdge(g1, 2, 3);
	
	printEulerTour(g1);
	
	Graph *g2=CreateGraph(3);
	addEdge(g2, 0, 1);
	addEdge(g2, 1, 2);
	addEdge(g2, 2, 0);
	
	printEulerTour(g2);
	
	Graph *g3=CreateGraph(5);
	addEdge(g3, 1, 0);
	addEdge(g3, 0, 2);
	addEdge(g3, 2, 1);
	addEdge(g3, 0, 3);
	addEdge(g3, 3, 4);
	addEdge(g3, 3, 2);
	addEdge(g3, 3, 1);
	addEdge(g3, 2, 4);
	
	printEulerTour(g3);

	return 0;
}
