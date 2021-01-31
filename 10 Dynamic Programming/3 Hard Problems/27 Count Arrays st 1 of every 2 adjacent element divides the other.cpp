#include<bits/stdc++.h>
using namespace std;
int Rec(int n,int m,int p,vector<vector<int>> &dp)
{
	if(n == 0)  return 1;
	
	if(dp[n][p] != -1)  return dp[n][p];
	
	dp[n][p] = 0;
	
	for(int i = 1 ; i <= m ; i++)
	{
		if(i > p && i%p == 0)  dp[n][p] += Rec(n-1 , m , i , dp);
		
		if(i <= p && p%i == 0)  dp[n][p] += Rec(n-1 , m , i , dp);
	}
	
	return dp[n][p];
}
int No_of_Arrays(int n,int m)
{
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	
	return Rec(n,m,1,dp);
}
signed main()
{
	int n = 3 , m = 3;
	
	cout<< No_of_Arrays(n,m) <<endl;
    
	return 0;
}
