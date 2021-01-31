#include<bits/stdc++.h>
using namespace std;
int KPartition(int n,int k)  // S(n,k) = k * S(n-1 , k) + S(n-1,k-1)
{
	int dp[n+1][k+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k;j++)
	{
		if(i==0 || j==0)  dp[i][j] = 0;
		
		else if(j==1 || i==j)  dp[i][j] = 1;
		
		else  dp[i][j] = dp[i-1][j] * j + dp[i-1][j-1];
	}
	return dp[n][k];
}
signed main()
{
	int n = 5 , k = 2;
	
	cout<< KPartition(n,k) <<endl;
    
	return 0;
}
