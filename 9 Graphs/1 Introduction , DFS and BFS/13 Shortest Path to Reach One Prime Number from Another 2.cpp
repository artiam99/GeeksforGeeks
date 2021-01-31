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
void seiveofEratosthenes(vector<int> &v)
{
	int n=9999;
	vector<bool> b(n+1,true);
	
	b[0]=b[1]=false;
	
	for(int i=2;i*i<=n;i++)
	{
		if(b[i])
		{
			for(int j=2;i*j<=n;j++)
			b[i*j]=false;
		}
	}
	
	for(int i=1000;i<=n;i++)
	if(b[i])
	v.push_back(i);
}
bool compare(int x,int y)
{
	string s1=to_string(x);
	string s2=to_string(y);
	
	int c=0;
	for(int i=0;i<s1.size();i++)
	if(s1[i]!=s2[i])
	c++;
	
	return (c==1);
}
int BFS(Graph* g,int s,int d)
{
	queue<int> q;
	
	vector<int> vis(g->V,0);
	
	q.push(s);
	vis[s]=1;
	
	while(q.size())
	{
		int x=q.front();
		q.pop();
		
		if(x==d)
		return vis[x]-1;
		
		for(auto i:g->adj[x])
		if(!vis[i])
		{
			vis[i]=vis[x]+1;
			q.push(i);
		}
	}
}
void FindShortestPath(int s,int d)
{
	vector<int> pset;
	seiveofEratosthenes(pset);
	
	Graph* g=CreateGraph(pset.size());
	
	for(int i=0;i<pset.size();i++)
	{
		for(int j=i+1;j<pset.size();j++)
		if(compare(pset[i],pset[j]))
		addEdge(g,i,j);
	}
	
	int ind1,ind2;
	for(int i=0;i<pset.size();i++)
	{
		if(pset[i]==s)
		ind1=i;
		else if(pset[i]==d)
		ind2=i;
	}
	
    cout<<BFS(g,ind1,ind2)<<endl;;
}
signed main()
{
	int s=1033;
	int d=8179;
	
	FindShortestPath(s,d);
		
	return 0;
}
