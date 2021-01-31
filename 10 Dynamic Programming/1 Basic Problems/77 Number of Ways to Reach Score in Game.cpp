#include<bits/stdc++.h>
using namespace std;
int ReachScore(int n)
{
	int a[] = {3,5,10};
	
	vector<int> dp(n+1);
	dp[0]=1;
	
	for(int i=0;i<3;i++)
	for(int j=a[i];j<=n;j++)
	dp[j]+=dp[j-a[i]];
	
	return dp[n];
}
signed main()
{
	int n = 20;
	
	cout<< ReachScore(n);
	
	return 0;
}
