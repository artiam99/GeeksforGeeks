#include<bits/stdc++.h>
using namespace std;
int MinimumChanges(vector<int> &a,int n)
{
	vector<int> dp(n,1);
	
	int len=1;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j] < a[i] && i-j <= a[i]-a[j])
	dp[i] = max(dp[i] , dp[j] + 1), len = max(len,dp[i]);
	
	return n-len;
}
signed main()
{
	vector<int> a = { 1, 2, 6, 5, 4 };
	int n = a.size();
	
	cout<< MinimumChanges(a,n) <<endl;
	
	return 0;
}
