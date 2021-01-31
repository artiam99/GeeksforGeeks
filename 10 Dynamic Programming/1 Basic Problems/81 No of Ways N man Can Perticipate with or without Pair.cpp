#include<bits/stdc++.h>
using namespace std;
int NoofWays(int n)
{
	int dp[n+1];
	
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++)
	dp[i] = dp[i-1] + dp[i-2]*(i-1);  // Participate alone or make couple with one of i-1 
	
	return dp[n];
}
signed main()
{
	int n = 3;
	
	cout<< NoofWays(n) <<endl;
	
	return 0;
}
