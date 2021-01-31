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
}
void DFS1(vector<int> &adj,int u,vector<bool> &vis,stack<int> &st)
{
	vis[u]=true;
	
	if(!vis[adj[u]])
	DFS1(adj,adj[u],vis,st);
	
	st.push(u);
}
void DFS2(vector<int> adj[],int u,vector<bool> &vis,int &cnt)
{
	vis[u]=true;
	
	cnt++;
	
	for(auto i:adj[u])
	if(!vis[i])
	DFS2(adj,i,vis,cnt);
}
int SCC(vector<int> &a,int n)
{
	vector<int> adj(n);
	
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		adj[i] = (i + a[i] + 1 ) % n;
		
		if(i==adj[i])// Self-Loops
		cnt++;
	}
	
	vector<bool> vis(n);
	stack<int> st;
	
	for(int i=0;i<n;i++)
	if(!vis[i])
	DFS1(adj,i,vis,st);
	
	vector<int> adjt[n];
	
	for(int i=0;i<n;i++)
	adjt[adj[i]].push_back(i);
	
	for(int i=0;i<n;i++)
	vis[i]=false;
	
	while(st.size())
	{
		if(!vis[st.top()])
		{
			int temp=0;
			DFS2(adjt,st.top(),vis,temp);
			
			if(temp > 1)
			cnt+=temp;
		}
		
		st.pop();
	}
	
	return cnt;
}
int NumberofElements(vector<int> &a,int n)
{
	return SCC(a,n);
}
signed main()
{
	vector<int> a = {3,0,0,0};
	int n1=a.size();
	
	cout<< NumberofElements(a,n1) <<endl;
	
	vector<int> b = {1,1,1,1};
	int n2=b.size();
	
	cout<< NumberofElements(b,n2) <<endl;
	
	return 0;
}
