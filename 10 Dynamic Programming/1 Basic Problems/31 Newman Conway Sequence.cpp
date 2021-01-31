#include<bits/stdc++.h>
using namespace std;
int NewmanConway(int n)
{
	vector<int> dp(n+1);
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	
	for(int i=3;i<=n;i++)
	dp[i] = dp[dp[i-1]] + dp[i - dp[i-1]];
	
	for(int i=1;i<=n;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
}
signed main()
{
	int n=20;
	
	NewmanConway(n); // P(n) = P(P(n)) + P(n-P(n-1))
	    
	return 0;
}
