#include<bits/stdc++.h>
using namespace std;
int Derangements(int n)
{
	vector<int> dp(n+1,-1);
	
	dp[0]=1;
	dp[1]=0;
	dp[2]=1;
	
	for(int i=3;i<=n;i++)
	dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
	
	return dp[n];
}
signed main()
{
	int n = 6;
	
	cout<< Derangements(n) <<endl;
    
	return 0;
}

