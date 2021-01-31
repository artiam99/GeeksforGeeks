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
	
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,vector<bool> &vis)
{
	vis[u]=true;
	
	for(auto i:g->adj[u])
	if(!vis[i])
	DFS(g,i,vis);
}
bool isConnected(Graph *g)
{
	vector<bool> vis(g->V);
	
	int u=0;
	for( ; u < g->V ; u++)
	if(g->adj[u].size())
	break;
	
	if(u==g->V)
	return true;
	
	DFS(g,u,vis);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i] && g->adj[u].size())
	return false;
	
	return true;
}
void isEulerian(Graph* g)
{
	if(!isConnected(g))
	{
		cout<<"Not Eulerian"<<endl<<endl;
		return;
	}
	
	int odd=0;
	
	for(int i=0;i<g->V;i++)
	if(g->adj[i].size() & 1)
	odd++;
	
	if(odd > 2)
	cout<<"Not Eulerian"<<endl;
	
	else if(odd)
	cout<<"Semi Eulerian"<<endl;
	
	else
	cout<<"Eulerinan"<<endl;
	
	cout<<endl;
}
signed main()
{
    Graph *g1=CreateGraph(5);
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 1);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);
    isEulerian(g1);

    Graph *g2=CreateGraph(5);
    addEdge(g2, 1, 0);
    addEdge(g2, 0, 2);
    addEdge(g2, 2, 1);
    addEdge(g2, 0, 3);
    addEdge(g2, 3, 4);
    addEdge(g2, 4, 0);
    isEulerian(g2);

    Graph *g3=CreateGraph(5);
    addEdge(g3, 1, 0);
    addEdge(g3, 0, 2);
    addEdge(g3, 2, 1);
    addEdge(g3, 0, 3);
    addEdge(g3, 3, 4);
    addEdge(g3, 1, 3);
    isEulerian(g3);
 
    Graph *g4=CreateGraph(3);
    addEdge(g4, 0, 1);
    addEdge(g4, 1, 2);
    addEdge(g4, 2, 0);
    isEulerian(g4);
  
    Graph *g5=CreateGraph(3);
    isEulerian(g5);
	
	return 0;
}
