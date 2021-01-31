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
bool ispresent(int x,vector<int> &mark)
{
	for(auto i:mark)
	if(i==x)
	return 1;
	
	return 0;
}
int BFT(Graph* g,int s,vector<int> &dis,vector<int> &mark)
{
	queue<int> q;
	
	q.push(s);
	
	dis[s]=0;
	
	int lastMarked=s;
	
	while(q.size())
	{
		int x=q.front();
		
		q.pop();
		
		if(ispresent(x,mark))
		lastMarked=x;
		
		for(auto i:g->adj[x])
		if(dis[i]==-1)
		{
			dis[i]=dis[x]+1;
			q.push(i);
		}
	}
	return lastMarked;
}
void NodesAtLessThanDistanceK(Graph* g,vector<int> &mark,int k)
{
	vector<int> temp(g->V,-1),dl(g->V,-1),dr(g->V,-1);
	
	int u=BFT(g,0,temp,mark);
	
	int v=BFT(g,u,dl,mark);
	
	BFT(g,v,dr,mark);
	
	for(int i=0;i<g->V;i++)
	if(dl[i]<=k && dr[i]<=k)
	cout<<i<<" ";
	
	cout<<endl;
}
signed main()
{
	int V=10;
	Graph* g=CreateGraph(V);
	
	addEdge(g, 1, 0);
    addEdge(g, 0, 3);
    addEdge(g, 0, 8);
    addEdge(g, 2, 3);
    addEdge(g, 3, 5);
    addEdge(g, 3, 6);
    addEdge(g, 3, 7);
    addEdge(g, 4, 5);
    addEdge(g, 5, 9);
    
    vector<int> mark={1,2,4};
    
    int k=3;
    
    NodesAtLessThanDistanceK(g,mark,3);
	
	return 0;
}
