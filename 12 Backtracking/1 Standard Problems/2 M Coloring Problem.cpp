#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Graph
{
    int V;
    vector<int> *adj;
};
Graph* CreateGraph(int V)
{
    Graph* g = new Graph;
    
    g->V = V;
    
    g->adj = new vector<int>[V];
    
    return g;
}
void addEdge(Graph* g,int u,int v)
{
    g->adj[u].push_back(v);
    g->adj[v].push_back(u);
}
bool NotDFS(Graph* g,int u,vector<int> &color,int M)
{
    if(u == g->V)  return true;
    
    for(int i = 0 ; i < M ; i++)
    {
        bool flag = true;
        
        for(auto j : g->adj[u])
        if(color[j] == i)
        {
            flag = false;
            
            break;
        }
        
        if(flag)
        {
            color[u] = i;
            
            if(NotDFS(g,u+1,color,M))
            return true;
        }
    }
    color[u] = -1;
    return false;
}
bool MColor(Graph* g,int M)
{
	vector<int> color(g->V,-1);
	    
	return NotDFS(g,0,color,M);
}
signed main()
{
	int V = 5 , M = 3;
	Graph* g = CreateGraph(5);
	
	addEdge(g, 0, 1);
	addEdge(g, 0, 3);
	addEdge(g, 1, 2);
	addEdge(g, 1, 3);
	addEdge(g, 1, 4);
	addEdge(g, 2, 4);
	addEdge(g, 3, 4);
	
	if(MColor(g,M))
	cout<< "YES" << endl;
	else
	cout<< "NO" << endl;
	
	return 0;
}
