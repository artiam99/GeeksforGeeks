#include<bits/stdc++.h>
using namespace std;
int countStrings(int n, int k)
{
	int mod = 1000000007;
	
    int dp[n+1][k+1][2];
    
    for(int i=0;i<=n;i++)
    for(int j=0;j<=k;j++)
    {
    	if(i==0)  dp[i][j][0] = dp[i][j][1] = 0;
    	
    	else if(i==1 && j==0)
    	dp[i][j][0]= dp[i][j][1] = 1;
    	
    	else
    	{
    		dp[i][j][0] = (dp[i-1][j][1] % mod + dp[i-1][j][0] % mod) % mod;
    	
    		dp[i][j][1] = (( (j > 0) ? dp[i-1][j-1][1] : 0 ) % mod + dp[i-1][j][0] % mod) % mod;
		}
	}
    
    return (dp[n][k][0] % mod + dp[n][k][1] % mod ) % mod;
}
signed main()
{
	int n = 5 , k = 2;
	
	cout<< countStrings(n,k) <<endl;
    
	return 0;
}
