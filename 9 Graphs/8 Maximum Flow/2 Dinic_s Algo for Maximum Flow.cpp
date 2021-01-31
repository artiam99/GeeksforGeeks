#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int v; 
    int flow; 
    int C; 
    int rev; 
};
struct Graph
{
	int V;
	vector<Edge> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<Edge>[V];
	
	return g;
}
void addEdge(Graph* g,int u, int v, int C)
{
	Edge a; a.v=v; a.flow=0; a.C=C; a.rev=g->adj[v].size();
	Edge b; b.v=v; b.flow=0; b.C=0; b.rev=g->adj[u].size();
	
    g->adj[u].push_back(a);
    g->adj[v].push_back(b); 
}
bool BFS(Graph* g,int s, int t,vector<int> &lvl)
{
    for(int i=0;i<g->V;i++)
    lvl[i]=-1;
    
    lvl[s]=0;
	 
    queue<int> q;
    q.push(s);
    
    while (q.size())
    {
        int u=q.front(); q.pop();
        
        for (auto i:g->adj[u])
        {
            Edge &e = i;
            
            if(lvl[e.v] == -1 && e.flow < e.C)
            {
                lvl[e.v] = lvl[u] + 1;
                
                q.push(e.v);
            }
        }
    }
    return (lvl[t] != -1);
}
int DFS(Graph* g,int s,int t,int flow,vector<int>& start,vector<int> &lvl)
{
	if(s==t)
	return flow;
	
    for ( ; start[s] < g->adj[s].size() ; start[s]++)
    {
        Edge &e = g->adj[s][start[s]];

        if (lvl[e.v] == lvl[s] + 1 && e.flow < e.C)
        {
            int curr_flow = min(flow, e.C - e.flow);
            
            int temp_flow = DFS(g,e.v,t, curr_flow,start,lvl);

            if (temp_flow > 0)
            {
                e.flow += temp_flow;
                
                g->adj[e.v][e.rev].flow -= temp_flow;
                
                return temp_flow;
            }
        }
    }
    return 0;
}

int Dinitz_Max_Flow(Graph* g,int s, int t)
{
    if(s == t)
    return -1;
    
    vector<int> lvl(g->V);
    
	int mx=0;
	
    while (BFS(g,s,t,lvl))
    {
        vector<int> start(g->V + 1);
        
        while (int flow = DFS(g,s,t,INT_MAX,start,lvl))
        mx += flow;
    }
    return mx;
}
signed main() 
{ 
    Graph *g=CreateGraph(6);
    
    addEdge(g, 0, 1, 16 );
    addEdge(g, 0, 2, 13 );
    addEdge(g, 1, 2, 10 );
    addEdge(g, 1, 3, 12 );
    addEdge(g, 2, 1, 4 );
    addEdge(g, 2, 4, 14);
    addEdge(g, 3, 2, 9 );
    addEdge(g, 3, 5, 20 );
    addEdge(g, 4, 3, 7 );
    addEdge(g, 4, 5, 4);
    
    int s=0,t=5;
    
	cout<< Dinitz_Max_Flow(g,0,5) <<endl;
    
    return 0;
}
