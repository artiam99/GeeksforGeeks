#include<bits/stdc++.h>
using namespace std;
int MinimumTrial(int n,int k)
{
	int dp[2][k+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k;j++)
	{
		if(i==0)  dp[i%2][j] = 0;
		
		else if(i==1 || j <= 1)  dp[i%2][j] = j;
		
		else
		{
			dp[i%2][j] = INT_MAX;
			
			for(int l=1;l<=j;l++)
			dp[i%2][j] = min(dp[i%2][j] , 1 + max(dp[1-i%2][l-1] , dp[i%2][j-l]));
		}
	}
	return dp[n%2][k];
}
signed main()
{
	int Egg = 2 , Floor = 10;
	
	cout<< MinimumTrial(Egg , Floor) <<endl;
    
	return 0;
}

