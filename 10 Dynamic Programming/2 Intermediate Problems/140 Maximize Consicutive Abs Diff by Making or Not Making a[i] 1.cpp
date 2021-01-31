#include<bits/stdc++.h>
using namespace std;
int MaxAbsDiff(vector<int> &a,int n)
{
	int dp[n][2];
	
	dp[0][0] = dp[1][0] = 0;
	
	for(int i = 1 ; i < n ; i++)
	{
		dp[i][0] = max(dp[i-1][0] + abs(a[i]-a[i-1]) , dp[i-1][1] + abs(a[i]-1));
		
		dp[i][1] = max(dp[i-1][0] + abs(1-a[i-1]) , dp[i-1][1] );
	}
	return max(dp[n-1][0] , dp[n-1][1]);
}
signed main()
{
	vector<int> a = {3, 2, 1, 4, 5};
	int n = a.size();
	
	cout<< MaxAbsDiff(a,n) <<endl;
	
	return 0;
}
