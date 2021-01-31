#include<bits/stdc++.h>
using namespace std;
int Rec(int n,vector<int> &b,int c,vector<vector<int>> &dp)
{
	if(n == 0)  return (c == 0);
	
	if(dp[n][c] != -1)  return dp[n][c];
	
	if(c == 0 && b[n] == 1) return dp[n][c] = 0;
	
	if(c > 0)
	{
		if(b[n] == 1)
		return dp[n][c] = Rec(n-1,b,c-1,dp);
		
		return dp[n][c] =  Rec(n-1,b,c-1,dp) + Rec(n-1,b,c+1,dp);
	}

	return dp[n][c] = Rec(n-1,b,c+1,dp);
}
int NoofExpression(vector<int> &a,int n)
{
	vector<int> b(n+1);
	
	for(auto i:a)
	b[i] = 1;
	
	//vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	
	//return Rec(n,b,0,dp);
	
	int dp[n+1][n+1];
	
	for(int i = 0 ; i <= n ; i++)
	for(int j = n ; j >= 0 ; j--)
	{
		if(i == 0) dp[i][j] = (j == 0);
		
		else if(j == 0 && b[i] == 1)  dp[i][j] = 0;
		
		else if(j > 0)
		{
			if(b[i] == 1)  dp[i][j] = dp[i-1][j-1];
			
			else  dp[i][j] = dp[i-1][j-1] + ((j < n) ? dp[i-1][j+1] : 0 ); 
		}
		else  dp[i][j] = dp[i-1][j+1];
	}
	return dp[n][0];
}
signed main()
{
	vector<int> a = {2};
	
	int n = 6;
	
	cout<< NoofExpression(a,n) <<endl;
	
	return 0;
}
