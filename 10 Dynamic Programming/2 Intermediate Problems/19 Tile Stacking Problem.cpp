#include<bits/stdc++.h>
using namespace std;
int NoofWays(int n,int m,int k)
{
	int dp[m+1][n+1] , pref[m+1][n+1];
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j==0)  dp[i][j] = pref[i][j] = 1;
			
			else if(i==0)  dp[i][j] = pref[i][j] = 0;
			
			else
			{
				dp[i][j] = pref[i-1][j];
				
				if(j>k)
				dp[i][j] -= pref[i-1][j-k-1];
			}
		}
		
		for(int j=1;j<=n;j++)
		pref[i][j] = pref[i][j-1] + dp[i][j];
	}
	
	return dp[m][n];
}
signed main()
{
	int n = 3 , m = 3, k =2; // No of ways to make Tower of hieght n using 1,2,..,m sized tiles (Each can be used at most k times) where larger tile cannot be placed on top of smaller 
    
    cout<< NoofWays(n,m,k);
    
	return 0;
}
