#include<bits/stdc++.h>
using namespace std;
int MaxProdCutting(int n)
{
	int dp[n+1];
	
	dp[1] = 0;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp[i] = 0;
		
		for(int j = 1 ; j < i ; j++)
		dp[i] = max( dp[i] , max( j * (i-j) , max( dp[j] * dp[i-j] , max( j * dp[i-j] , dp[j] * (i-j) ))));
	}
	return dp[n];
}
signed main()
{
	int n = 10; // 3 * 3 * 4
	
	cout<< MaxProdCutting(n) <<endl;
    
	return 0;
}
