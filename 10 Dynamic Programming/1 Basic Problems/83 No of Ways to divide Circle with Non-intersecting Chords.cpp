#include<bits/stdc++.h>
using namespace std;
int NoofWays(int N)
{
	int dp[N+1];
	memset(dp,0,sizeof(dp));
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=N;i++)
	for(int j=0;j<i;j++)
	dp[i]+=dp[j]*dp[i-j-1];
	
	return dp[N];
}
signed main()
{
	int  N= 4;
	
	cout<< NoofWays(N) <<endl;
	
	N= 2;
	
	cout<< NoofWays(N) <<endl;
	
	
	N= 1;
	
	cout<< NoofWays(N) <<endl;
	
	return 0;
}
