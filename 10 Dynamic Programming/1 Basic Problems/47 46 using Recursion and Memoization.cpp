#include<bits/stdc++.h>
using namespace std;
int CountUntill(int m,int n,vector<vector<int>> &dp)
{
	if(m < n)
	return 0;
	
	if(n==0)
	return 1;
	
	if(dp[m][n] != -1)
	return dp[m][n];
	
	return dp[m][n] = CountUntill(m-1,n,dp) + CountUntill(m/2,n-1,dp);
}
int CountSequence(int m,int n)
{
	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	
	return CountUntill(m,n,dp);
}
signed main()
{
	int m = 10 , n = 4;// Max element <= m ... Size n 
    
    cout<< CountSequence(m,n);
    
	return 0;
}
