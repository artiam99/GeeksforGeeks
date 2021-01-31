#include<bits/stdc++.h>
using namespace std;
int Bell(int n)
{
	vector<vector<int>> dp(n,vector<int>(n));
	
	dp[0][0]=1;
	
	for(int i=1;i<n;i++)
	{
		dp[i][0]=dp[i-1][i-1];
		
		for(int j=0;j<i;j++)
		dp[i][j+1] = dp[i][j] + dp[i-1][j];
	}
	
	return dp[n-1][n-1];
}
int sqrtfreepartition(int n)
{
	int prime=0;
	
	while(n%2==0)
	{
		prime++;
		n/=2;
	}
	
	for(int i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			prime++;
			n/=i;
		}
	}
	
	if(n>2)
	prime++;
	
	
	return Bell(prime);
}
signed main()
{
    int n=30;
    
    cout<< sqrtfreepartition(n) <<endl;
    
	return 0;
}
