#include<bits/stdc++.h>
using namespace std;
void Knapsack(int W,vector<int> &wt,vector<int> &val,int n)
{
	int dp[n+1][W+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=W;j++)
	{
		if(i==0 || j==0)  dp[i][j] = 0;
		
		else if(j >= wt[i-1])  dp[i][j] = max(dp[i-1][j] , dp[i-1][j-wt[i-1]] + val[i-1]);  // dp[i-1][j-wt[i-1]] doesn't matter as we don't have to make perfect j...j is Max Limit
		
		else  dp[i][j] = dp[i-1][j];
	}
	
	cout<< dp[n][W] <<endl;
	
	for(int i=n;i>0;i--)
	{
		if(dp[i][W] == 0) break;
		
		if(dp[i][W] != dp[i-1][W])
		{
			cout<< wt[i-1] <<" ";
			
			W -= wt[i-1];
		}
	}
	cout<<endl;
}
signed main()
{
	int W = 50;
	
	vector<int> val = {60, 100, 120};
	vector<int> wt = {10, 20, 30};
	
	int n = wt.size();
	
	Knapsack(W,wt,val,n);
    
	return 0;
}

