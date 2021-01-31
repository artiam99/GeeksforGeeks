#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	vector<pair<int,int>> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<pair<int,int>>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back({v,0});
	g->adj[v].push_back({u,1});
}
int DFT(Graph* g,vector<pair<int,int>> &DisBack,int u,vector<bool> &vis)
{
	vis[u]=true;
	
	int totalBack=0;
	
	for(auto i:g->adj[u])
	{
		if(!vis[i.first])
		{
			DisBack[i.first].first=DisBack[u].first+1;
			
			DisBack[i.first].second=DisBack[u].second;
			
			if(i.second)
			{
				DisBack[i.first].second++;
				
				totalBack++;
			}
			
			totalBack+=DFT(g,DisBack,i.first,vis);
		}
	}
	return totalBack;
}
void FindRoot(Graph* g)
{
	vector<pair<int,int>> DisBack(g->V);// To Store Distance from starting Node and BackEdges So far
	
	vector<bool> vis(g->V,false);
	
	int totalBack=DFT(g,DisBack,0,vis);
	
	int Res=INT_MAX;
	int Root;
	
	for(int i=0;i<g->V;i++)
	{
		int res=(totalBack - DisBack[i].second)// Total Number of BackEdge - BackEdge Sofar == BackEdges after ith Node
		        +(DisBack[i].first - DisBack[i].second);// Distance Sofar - BackEdges(Non Resversing Edges)
		        
	    if(res<Res)
	    {
	    	Res=res;
	    	Root=i;
		}
	}
	
	cout<<"Root is "<<Root<<" and Minimum Edge Reversal is "<<Res<<endl;
}
signed main()
{
	int V=8;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,2,1);
	addEdge(g,3,2);
	addEdge(g,3,4);
	addEdge(g,5,4);
	addEdge(g,5,6);
	addEdge(g,7,6);
	
	FindRoot(g);
	
	return 0;
}
