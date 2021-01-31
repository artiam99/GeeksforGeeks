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
int findNodeCount(Graph* g,int lvl)
{
	queue<int> q;
	
	vector<bool> vis(g->V,false);
	
	if(g->V)
	q.push(0);
	
	vis[0]=true;
	
	int cnt=0;
	
	if(cnt==lvl)
	return 1;
	
	while(q.size())
	{
		int size=q.size();
		while(size--)
		{
			int x=q.front();
			q.pop();
			
			for(auto i:g->adj[x])
			{
				if(!vis[i])
				{
					vis[i]=true;
					q.push(i);
				}
			}
		}
		cnt++;
		
		if(cnt==lvl)
		return q.size();
	}
	return -1;
}
signed main()
{
	int V=6;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,3);
	addEdge(g,2,4);
	addEdge(g,2,5);
	
	int lvl=2;
	cout<<findNodeCount(g,lvl)<<endl;
	
	return 0;
}
