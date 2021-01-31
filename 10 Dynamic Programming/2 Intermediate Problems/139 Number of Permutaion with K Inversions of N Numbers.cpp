#include<bits/stdc++.h>
using namespace std;
int KInversions(int n,int k)
{
	int dp[n][k+1];
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j <= k ; j++)
	{
		if(i == 0)  dp[i][j] = (j==0);
		
		else if(j == 0)  dp[i][j] = 1;
		
		else
		dp[i][j] =  dp[i][j-1] + dp[i-1][j] - (( max(j-i , 0) == 0) ? 0 : dp[i-1][max(j-i,0)-1]);
	}
	return dp[n-1][k];
}
signed main()
{
	int n = 5 , k = 5;
	
	cout<< KInversions(n,k) <<endl;
	
	return 0;
}
