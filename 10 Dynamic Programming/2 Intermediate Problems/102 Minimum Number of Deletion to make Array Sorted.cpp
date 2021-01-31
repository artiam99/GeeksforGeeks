#include<bits/stdc++.h>
using namespace std;
int MinDeletion(vector<int> &a,int n)
{
	vector<int> dp(n,INT_MAX);
	
	for(int i=0;i<n;i++)
	dp[upper_bound(dp.begin(),dp.end(),a[i])-dp.begin()] = a[i];
	
	return n - ( lower_bound(dp.begin(),dp.end(),INT_MAX) - dp.begin() ); // N - LNDS
}
signed main()
{
	vector<int> a = {5, 6, 1, 7, 4};
	int n = a.size();
	
	cout<< MinDeletion(a,n) <<endl;
	
	return 0;
}
