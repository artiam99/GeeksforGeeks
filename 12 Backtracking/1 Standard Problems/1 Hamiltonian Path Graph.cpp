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
bool DFS(Graph* g,int u,vector<bool> &vis,int n,vector<int> &ans)
{   
    vis[u] = true;
    n++;
    
    if(n == g->V)
    return true;
    
    for(auto i:g->adj[u])
    if(!vis[i])
    {
    	ans.push_back(i);
    	
    	if(DFS(g,i,vis,n,ans))
    	return true;
    	
    	ans.pop_back();
	}
    
    vis[u] = false;
    
    return false;
}
void Hamiltonian(Graph* g)
{
    int mn = INT_MAX , u;
    
    for(int i = 0 ; i < g->V ; i++)
    if(mn > g->adj[i].size())
    {
        mn = g->adj[i].size();
        
        u = i;
    }
    
    if(mn == 0 || mn == INT_MAX)
    {
        cout<< "No Hamiltonian Path" << endl << endl;
        
        return;
    }
    
    bool flag = 0;
    
    vector<bool> vis(g->V);
    
	vector<int> ans;
	
	ans.push_back(u);
    
    if(DFS(g,u,vis,0,ans))
    {
    	bool flag = false;
    	
    	for(auto i:g->adj[ans[g->V-1]])
    	if(i == u)
    	{
    		flag = true;
    		
    		break;
		}
    	
    	if(flag)
    	cout<< "Hamiltonian Cycle : ";
    	else
    	cout<< "Hamiltonian Path : ";
    	
    	for(auto i:ans)
    	cout<< i << " ";
    	
    	if(flag)
    	cout<< u;
	}
    else
    cout<< "No Hamiltonian Path";
    
    cout<< endl << endl;
}
signed main()
{	
	Graph* g1 = CreateGraph(5);
	
	addEdge(g1, 0, 1);
	addEdge(g1, 0, 3);
	addEdge(g1, 1, 2);
	addEdge(g1, 1, 3);
	addEdge(g1, 1, 4);
	addEdge(g1, 2, 4);
	addEdge(g1, 3, 4);
	
	Hamiltonian(g1);
	
	Graph* g2 = CreateGraph(5);
	
	addEdge(g2, 0, 1);
	addEdge(g2, 0, 3);
	addEdge(g2, 1, 2);
	addEdge(g2, 1, 3);
	addEdge(g2, 1, 4);
	addEdge(g2, 2, 4);
	
	Hamiltonian(g2);
	    
	return 0;
}
