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
	g->adj[v].push_back(u);
}
int DFT(Graph* g,int x,int &total,vector<bool> &vis)
{
	vis[x]=true;
	
	int max1=0,max2=0;
	
	for(auto i:g->adj[x])
	{
		if(!vis[i])
		{
			int x=DFT(g,i,total,vis);
			
			if(x > max1)
			{
				max2=max1;
				
				max1=x;
			}
			else
			max2=max(max2,x);
		}
	}
	
	total=max(total,max1+max2);
	
	return max1+1;
}
int MaximumProduct(Graph* g)
{
	int mx=INT_MIN;
	for(int i=0;i<g->V;i++)
	{
		for(auto j:g->adj[i])
		{
			if(j>i)
			{
				vector<bool> vis(g->V,false);
				vis[i]=vis[j]=true;
				
				int path1=0;
				DFT(g,i,path1,vis);
				
				int path2=0;
				DFT(g,j,path2,vis);
				
				mx=max(mx,path1*path2);
			}
		}
	}
	return mx;
}
signed main()
{
	int V=9;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,1,3);
	addEdge(g,1,8);
	addEdge(g,3,5);
	addEdge(g,8,4);
	addEdge(g,8,7);
	addEdge(g,8,6);
	addEdge(g,6,2);
	
	cout<<MaximumProduct(g)<<endl;
	
	return 0;
}
