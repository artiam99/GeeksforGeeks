#include<bits/stdc++.h>
using namespace std;
int CountSequence(int m,int n)
{
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=m;i++)
	dp[1][i] = i;
	
	for(int i=2;i<=n;i++)
	for(int j=1;j<=m;j++)
	dp[i][j] = ( (j >= i) ? dp[i][j-1] + dp[i-1][j/2] : 0);
	
	return dp[n][m];
}
signed main()
{
	int m = 10 , n = 4;// Max element <= m ... Size n 
    
    cout<< CountSequence(m,n);
    
	return 0;
}
