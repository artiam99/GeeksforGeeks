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
void DFTUntill(Graph* g,int s,vector<bool> &vis)
{
	stack<int> st;
	
	st.push(s);
	
	cout<<s<<" ";
	
	while(st.size())
	{
		int top=st.top();
		
		bool flag=0;
		
		for(int i=0;i<g->adj[top].size();i++)
		{
			if(!vis[ g->adj[top][i] ])
			{
				st.push(g->adj[top][i]);
				
				cout<<g->adj[top][i]<<" ";
				
				vis[g->adj[top][i]]=true;
				
				flag=1;
				
				break;
			}
		}
		
		if(!flag)
		st.pop();
	}
}
void DFT(Graph* g)
{
	vector<bool> vis(g->V,false);
	
	for(int i=0;i<g->V;i++)
	if(!vis[i])
	DFTUntill(g,i,vis);
	
	cout<<endl;
}
signed main()
{
	int V=5;
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,3);
	addEdge(g,2,4);
	
	DFT(g);
    
	return 0;
}
