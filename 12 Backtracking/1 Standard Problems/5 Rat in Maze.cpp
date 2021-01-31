#include<bits/stdc++.h>
using namespace std;
bool DFS(int x,int y,vector<vector<bool>> &a,int n,vector<vector<bool>> &ans)
{
	ans[x][y] = 1;
	
	if(x == n-1 && y == n-1)  return true;
	
	if(x+1 < n && a[x+1][y] && DFS(x+1,y,a,n,ans))  return true;
	
	if(y+1 < n && a[x][y+1] && DFS(x,y+1,a,n,ans))  return true;
	
	ans[x][y] = 0;
}
void Rat(vector<vector<bool>> &a,int n)
{
	vector<vector<bool>> ans(n,vector<bool>(n,0));
	
	if(a[0][0] && a[n-1][n-1])
	DFS(0,0,a,n,ans);
	
	for(auto i : ans)
	{
		for(auto j : i)
		cout<< j << " ";
		cout<< endl;
	}
}
signed main()
{
	vector<vector<bool>> a = { { 1, 1, 1, 0 }, 
                    		   { 1, 0, 1, 1 }, 
                       		   { 1, 1, 1, 0 }, 
                       		   { 0, 0, 1, 1 } }; 
	int n = a.size();
	
	Rat(a,n);
	
	return 0;
}
