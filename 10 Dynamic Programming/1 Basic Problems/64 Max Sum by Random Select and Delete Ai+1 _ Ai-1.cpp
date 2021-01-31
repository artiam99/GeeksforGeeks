#include<bits/stdc++.h>
using namespace std;
int MaxSum(vector<int> &a,int n)
{
	unordered_map<int,int> dp;
	
	for(int i=0;i<n;i++)
	dp[a[i]]++;
	
	int mx = *max_element(a.begin(),a.end());
	
	for(int i=2;i<=mx;i++)
	dp[i] = max(dp[i-1] , dp[i-2] + dp[i]*i);
	
	return dp[mx];
}
signed main()
{
	vector<int> a = {1, 2, 2, 2, 3, 4};
	int n = a.size();
	
	cout<< MaxSum(a,n) <<endl;
    
	return 0;
}
