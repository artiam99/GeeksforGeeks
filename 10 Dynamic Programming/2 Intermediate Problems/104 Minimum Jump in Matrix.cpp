#include<bits/stdc++.h>
using namespace std;
int MinJumps(vector<vector<int>> &a,int n,int m)
{
	int dp[n][m];
	
	dp[0][0] = 0;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(!(i==0 && j==0))
	dp[i][j]=min( ((i > 0 && j > 0) ? abs(a[i][j]-a[i-1][j-1]) + dp[i-1][j-1]  : INT_MAX) ,
				  
				   min( ((j > 0) ? abs(a[i][j-1]-a[i][j]) + dp[i][j-1] : INT_MAX) , ((i > 0) ? abs(a[i-1][j]-a[i][j]) + dp[i-1][j] : INT_MAX) ) );
	
	return dp[n-1][m-1];
}
signed main()
{
	vector<vector<int>> a = { { 5, 4, 2 },
                           	  { 9, 2, 1 },
                           	  { 2, 5, 9 },
                              { 1, 3, 11} };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MinJumps(a,n,m) <<endl;
	
	return 0;
}
