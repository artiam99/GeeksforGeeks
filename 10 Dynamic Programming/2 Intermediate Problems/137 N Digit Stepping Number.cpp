#include<bits/stdc++.h>
using namespace std;
int NDigitStepping(int n)
{
	int dp[n][10];
	
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0 ; j < 10 ; j++)
		{
			if(i==0)  dp[i][j] = 1;
			
			else
			dp[i][j] = ((j > 0) ? dp[i-1][j-1] : 0) + ((j < 9) ? dp[i-1][j+1] : 0);
		}
	}
	int ans = 0;
	
	for(int i = 1 ; i < 10 ; i++)
	ans += dp[n-1][i];
	
	return ans;
}
signed main()
{
	int n = 2;
	
	cout<< NDigitStepping(n) <<endl;
	
	return 0;
}
