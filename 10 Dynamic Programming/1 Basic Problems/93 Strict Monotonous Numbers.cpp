#include<bits/stdc++.h>
using namespace std;
int MonotonousNumbers(int n)
{
	int dp[2][9];
	
	for(int i=0;i<9;i++)
	dp[0][i]=9-i;
	
	for(int i=1;i<n;i++)
	for(int j=8;j>=0;j--)
	{
		if(j==8)  dp[i%2][j] = 0;
		
		else  dp[i%2][j] = dp[1-i%2][j+1] + dp[i%2][j+1];
	}
	
	return dp[1-n%2][0];
}
signed main()
{
	int n = 4;
	
	cout<< MonotonousNumbers(n) <<endl;
	
	return 0;
}
