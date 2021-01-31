#include<bits/stdc++.h>
using namespace std;
int CircularLIS(vector<int> &a,int n)
{
	int mx = 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		vector<int> dp(n,INT_MAX);
		
		for(int j = i ; j < i+n ; j++)
		dp[lower_bound(dp.begin(),dp.end(),a[j%n])-dp.begin()] =a[j%n];
		
		mx = max(mx,(int)(lower_bound(dp.begin(),dp.end(),INT_MAX)-dp.begin()));
	}
	return mx;
}
signed main()
{
	vector<int> a = {5,6,7,1,2,3,4};
	int n = a.size();
	
	cout<< CircularLIS(a,n) <<endl;
	
	return 0;
}
