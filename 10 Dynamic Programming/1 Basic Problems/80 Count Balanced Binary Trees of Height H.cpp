#include<bits/stdc++.h>
using namespace std;
int BBT(int n)
{
	int dp[n+1];
	
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++)
	dp[i] = dp[i-1]*dp[i-1] + dp[i-1]*dp[i-2] + dp[i-2]*dp[i-1];
	
	return dp[n];
}
signed main()
{
	int n = 3;
	
	cout<< BBT(n) <<endl;
	
	return 0;
}
