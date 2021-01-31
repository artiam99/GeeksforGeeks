#include<bits/stdc++.h>
using namespace std;
int Rec(int n,int k,vector<vector<int>> &dp)
{
	if(n == 0)  return 0;
	
	if(n==1 || k <= 1)  return k;// if we have one egg we need to drop it from the lowest floor to get the pivot
	
	if(dp[n][k] != -1)  return dp[n][k];
	
	dp[n][k] = INT_MAX;
	
	for(int i=1;i<=k;i++)
	dp[n][k] = min(dp[n][k] , 1 + max(Rec(n-1,i-1,dp) , Rec(n,k-i,dp)));
	
	return dp[n][k];
}
int MinimumTrial(int n,int k)
{
	vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
	
	return Rec(n,k,dp);
}
signed main()
{
	int Egg = 2 , Floor = 10;// Minimum Number of Egg Drops to find the Pivot from where an egg survives but doesnt survivies dropping from one floor high
	
	cout<< MinimumTrial(Egg , Floor) <<endl;
    
	return 0;
}

