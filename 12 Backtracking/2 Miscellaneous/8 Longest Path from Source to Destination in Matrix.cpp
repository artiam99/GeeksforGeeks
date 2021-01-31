#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<bool>> &a,int n,int m,int ux,int uy,int dx,int dy,vector<vector<bool>> &vis,int cnt,int &mx)
{
	cnt++;
	
	if(ux == dx && uy == dy)
	{
		mx = max(mx , cnt);
		
		cnt--;
		
		return;
	}
	vis[ux][uy] = true;
	a[ux][uy] = false;
	
	if(ux > 0 && a[ux-1][uy] && !vis[ux-1][uy])
	DFS(a,n,m,ux-1,uy,dx,dy,vis,cnt,mx);
	
	if(ux < n-1 && a[ux+1][uy] && !vis[ux+1][uy])
	DFS(a,n,m,ux+1,uy,dx,dy,vis,cnt,mx);
	
	if(uy > 0 && a[ux][uy-1] && !vis[ux][uy-1])
	DFS(a,n,m,ux,uy-1,dx,dy,vis,cnt,mx);
	
	if(uy < m && a[ux][uy+1] && !vis[ux][uy+1])
	DFS(a,n,m,ux,uy+1,dx,dy,vis,cnt,mx);
	
	vis[ux][uy] = false;
	a[ux][uy] = true;
	
	cnt--;
}
int Longest_Path(vector<vector<bool>> &a,int n,int m,int sx,int sy,int dx,int dy)
{
	int mx = 0 , cnt = 0;
	
	vector<vector<bool>> vis(n,vector<bool>(n));
	
	if(a[sx][sy] && a[dx][dy])
	DFS(a,n,m,sx,sy,dx,dy,vis,cnt,mx);
	
	return mx-1;
}
signed main()
{
	vector<vector<bool>> a = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						       { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
						       { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
	int n = a.size();
	int m = a[0].size();
	
	cout<< Longest_Path(a,n,m,0,0,1,7) << endl;

	return 0;
}
