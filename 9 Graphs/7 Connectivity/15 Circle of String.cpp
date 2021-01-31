#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int> adj[],int u,vector<bool> &vis)
{
	vis[u]=true;
	for(auto i:adj[u])
	if(!vis[i])
	DFS(adj,i,vis);
}
bool isStronglyConnected(vector<int> adj[],int n,vector<int> &in,vector<int> &out)
{
	vector<bool> vis(n);
	
	if(adj[0].size())
	DFS(adj,0,vis);
	
	for(auto i:vis)
	if(!i)
	return false;
	
	vector<int> adjt[n];
	
	for(int i=0;i<n;i++)
	{
		for(auto j:adj[i])
		adjt[j].push_back(i);
	}
	
	for(int i=0;i<n;i++)
	vis[i]=false;
	
	if(adjt[0].size())
	DFS(adjt,0,vis);
	
	for(auto i:vis)
	if(!i)
	return false;
	
	for(int i=0;i<n;i++)
	{
		in[i]=adjt[i].size();
		out[i]=adj[i].size();
	}
	return true;
}
bool isCircle(vector<string> &a,int n)
{
	unordered_map<char,vector<int>> pre;
	
	for(int i=0;i<n;i++)
	pre[a[i][0]].push_back(i);
	
	vector<int> adj[n];
	
	for(int i=0;i<n;i++)
	{
		for(auto j:pre[a[i][a[i].length()-1]])
		adj[i].push_back(j);
	}
	
	vector<int> in(n),out(n);
	
	if(isStronglyConnected(adj,n,in,out))
	{
		for(int i=0;i<n;i++)
		if(in[i] != out[i])
		return false;
		
		return true;
	}
	return false;
}
signed main()
{
    vector<string> a = {"for", "geek", "rig", "kaf"};
    int n=a.size();
    
    if(isCircle(a,n))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
	
	return 0;
}
