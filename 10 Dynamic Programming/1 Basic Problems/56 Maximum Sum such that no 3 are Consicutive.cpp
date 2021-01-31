#include<bits/stdc++.h>
using namespace std;
int MaxSum(vector<int> &a,int n)
{
	vector<int> dp(n);
	
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	dp[2] = max(max(dp[1] , dp[0]+a[2]) , a[1] + a[2]);
	
	for(int i=3;i<n;i++)
	dp[i] = max(max(dp[i-1] , dp[i-2] + a[i]) , dp[i-3] + a[i-1] + a[i]);
	
	return dp[n-1];
}
signed main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = a.size();
    
    cout<< MaxSum(a,n) <<endl;
    
	return 0;
}
