#include<bits/stdc++.h>
using namespace std;
#define int long long
void DFS(vector<pair<int,int>> adj[],int u,int dest,int avg,vector<int> &ans,vector<int> &curr,vector<bool> &vis,int cost,int &mn)
{
	if(u==dest)
	{
		if(cost < mn)
		{
			mn=cost;
			ans=curr;
		}
		
		return;
	}
	
	vis[u]=true;
	
	for(auto i:adj[u])
	if(!vis[i.first])
	{
		curr.push_back(i.first);
		
		DFS(adj,i.first,dest,avg,ans,curr,vis,cost+abs(i.second-avg),mn);
		
		curr.pop_back();
	}
	
	vis[u]=false;
}
void PrintOptimalReadList(vector<int> &a,int n,int k)
{
	for(int i=1;i<n;i++)
	a[i]+=a[i-1];
	
	vector<pair<int,int>> adj[n+1];
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		adj[i].push_back({j,a[j-1]-((i)?a[i-1]:0)});
	}
	
	int avg=a[n-1]/k;
	
	vector<int> ans,curr;
	
	vector<bool> vis(n+1);
	
	int mn=INT_MAX;
	
	curr.push_back(0);
	
	DFS(adj,0,n,avg,ans,curr,vis,0,mn);
	
	for(int i=1;i<ans.size();i++)
	{
		for(int j=ans[i-1];j<ans[i];j++)
		cout<<j+1<<" ";
		cout<<endl;
	}
}
signed main()
{
	vector<int> a={8,5,6,12};
	int n=a.size();
	
	int k=3;
	
	PrintOptimalReadList(a,n,k);
	
	return 0;
}
