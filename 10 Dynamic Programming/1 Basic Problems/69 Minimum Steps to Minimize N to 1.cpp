#include<bits/stdc++.h>
using namespace std;
int MinSteps(int n)
{
	vector<int> dp(n+1);
	
	for(int i=1;i<=n;i++)
	dp[i] = n-i;
	
	for(int i=n-1;i>=1;i--)
	{
		if(i*2 <= n)
		dp[i] = min(dp[i] , dp[i*2] + 1);
		
		if(i*3 <= n)
		dp[i] = min(dp[i] , dp[3*i] + 1);
	}
	return dp[1];
}
signed main()
{
	int n = 10;
	
	cout<< MinSteps(n) <<endl;
    
	return 0;
}
