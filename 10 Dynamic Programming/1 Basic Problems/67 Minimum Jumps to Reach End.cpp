#include<bits/stdc++.h>
using namespace std;
int MinJump(vector<int> &a,int n)
{
	vector<int> dp(n,INT_MAX);
	dp[0]=0;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	if(j + a[j] >= i)
	dp[i] = min(dp[i] , dp[j] + 1);
	
	return ( (dp[n-1] != INT_MAX) ? dp[n-1] : -1);
}
signed main()
{
	vector<int> a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = a.size();
	
	cout<< MinJump(a,n) <<endl;
    
	return 0;
}
