#include<bits/stdc++.h>
using namespace std;
int Max_A(int N)
{
	int dp[N];
	
	dp[0] = 1;
	
	for(int i = 1 ; i < N ; i++)
	{
		dp[i] = dp[i-1] + 1;
		
		for(int j = 3 ; j <= i ; j++)
		dp[i] = max(dp[i] , dp[j-3] + dp[j-3] * (i - j + 1));
	}
	
	return dp[N-1];
}
signed main()
{
	int N = 14;
	
	cout<< Max_A(N) <<endl;
    
	return 0;
}
