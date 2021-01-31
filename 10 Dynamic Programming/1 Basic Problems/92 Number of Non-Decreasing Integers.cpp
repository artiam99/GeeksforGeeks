#include<bits/stdc++.h>
using namespace std;
int NonDecreasingIntegers(int n)
{
	vector<vector<int>> dp(n+1,vector<int>(10,1));
	
	for(int i=1;i<=n;i++)
	for(int j=8;j>=0;j--)
	dp[i][j] = dp[i-1][j] + dp[i][j+1];
	
	return dp[n][0];
}
signed main()
{
	int n = 4;
	
	cout<< NonDecreasingIntegers(n) <<endl;
	
	return 0;
}
