#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
bool DFS(vector<int> adj[],int u,vector<bool> &vis,vector<bool> &recstk)
{
	vis[u]=true;
	recstk[u]=true;
	
	for(auto i:adj[u])
	{
		if(!vis[i] && DFS(adj,i,vis,recstk))
		return true;
		
		else if(recstk[i])
		return true;
	}
	recstk[u]=false;
	
	return false;
}
bool findLoop(vector<int> &a,int n)
{
	vector<int> adj[n];
	
	for(int i=0;i<n;i++)
	if(a[i]%n)
	adj[i].push_back((i+a[i])%n);
	
	vector<bool> vis(n,false);
	vector<bool> recstk(n,false);
	
	for(int i=0;i<n;i++)
	{
		if(DFS(adj,i,vis,recstk))
		return true;
	}
	return false;
}
signed main()
{
	vector<int> a={2,-1,1,2,2};
	int n=a.size();
	
	if(findLoop(a,n))
	cout<<"Loop Present"<<endl;
	else
	cout<<"Loop Not Present"<<endl;
	
	return 0;
}
