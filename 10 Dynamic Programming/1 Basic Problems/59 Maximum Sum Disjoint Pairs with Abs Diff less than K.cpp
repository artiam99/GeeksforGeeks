#include<bits/stdc++.h>
using namespace std;
int MaxSumPair(vector<int> &a,int n,int k)
{
	sort(a.begin(),a.end());
	
	vector<int> dp(n);
	
	for(int i=1;i<n;i++)
	{
		dp[i] = dp[i-1];
		
		if(a[i] - a[i-1] < k)
		dp[i] = max(dp[i] , ((i >= 2) ? dp[i-2] : 0) + a[i-1] + a[i]);
	}
	return dp[n-1];
}
signed main()
{
	vector<int> a = {3, 5, 10, 15, 17, 12, 9};
	int n = a.size();
	int k = 4;
	
	cout<< MaxSumPair(a,n,k) <<endl;
    
	return 0;
}
