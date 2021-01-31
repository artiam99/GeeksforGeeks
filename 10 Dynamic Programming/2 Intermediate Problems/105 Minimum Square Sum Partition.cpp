#include<bits/stdc++.h>
using namespace std;
int MinSquare(int n)
{
	int dp[n+1];
	
	dp[0] = 0 , dp[1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp[i] = INT_MAX;
		
		for(int j = 1 ; j * j <= i ; j++)
		dp[i] = min( dp[i] , dp[i-j*j] + 1);
	}
	return dp[n];
}
signed main()
{
	int n = 12;
	
	cout<< MinSquare(n) <<endl;
	
	return 0;
}
