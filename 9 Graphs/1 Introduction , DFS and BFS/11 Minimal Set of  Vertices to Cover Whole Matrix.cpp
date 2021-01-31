#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void DFT(int adj[][3],int i,int j,int r,int c,bool vis[][3])
{
	if(vis[i][j])
	return;
	
	vis[i][j]=true;
	
	if(i>0 && adj[i][j]>=adj[i-1][j])
	DFT(adj,i-1,j,r,c,vis);
	
	if(i<r-1 && adj[i][j]>=adj[i+1][j])
	DFT(adj,i+1,j,r,c,vis);
	
	if(j>0 && adj[i][j]>=adj[i][j-1])
	DFT(adj,i,j-1,r,c,vis);
	
	if(j<c-1 && adj[i][j]>=adj[i][j+1])
	DFT(adj,i,j+1,r,c,vis);
	
}
void MinimalSet(int adj[][3],int r,int c)
{
	vector<pair<int,pair<int,int>>> a;
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		a.push_back({adj[i][j],{i,j}});
	}
	
	sort(a.begin(),a.end());
	
	bool vis[3][3];
	memset(vis,0,sizeof(vis));
	
	for(int i=a.size()-1;i>=0;i--)
	{
		if(!vis[a[i].second.first][a[i].second.second])
		{
			cout<<a[i].second.first<<" "<<a[i].second.second<<endl;
			
			DFT(adj,a[i].second.first,a[i].second.second,r,c,vis);
		}
	}
}
signed main()
{
	int adj[3][3]={{1,3,2},
	               {2,1,3},
				   {1,1,1}};
	
	MinimalSet(adj,3,3);
	
	return 0;
}
