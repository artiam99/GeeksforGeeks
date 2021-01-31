#include<bits/stdc++.h>
using namespace std;
int MaxMatch(int n)
{
	vector<int> dp(n);
	dp[0]=1;
	dp[1]=2;
	
	int i=2;
	while(dp[i-1] <= n)
	{
		dp[i] = dp[i-1] + dp[i-2];
		i++;
	}
	return i-2;
}
signed main()
{
	int n = 100;
	
	cout<< MaxMatch(n) <<endl;
    
	return 0;
}
