#include<bits/stdc++.h>
using namespace std;
int RemoveUntill(vector<int> &a,int l,int r,int k,vector<vector<int>> &dp)
{
	if(l>=r)
	return 0;
	
	if(a[r] - a[l] <= k)
	return 0;
	
	if(dp[l][r] != -1)
	return dp[l][r];
	
	return dp[l][r] = min( RemoveUntill(a,l+1,r,k,dp) , RemoveUntill(a,l,r-1,k,dp) ) + 1;
	
}
int MinRemov(vector<int> &a,int n,int k)
{
	sort(a.begin(),a.end());
	
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	return RemoveUntill(a,0,n-1,k,dp);
}
signed main()
{
	vector<int> a = {1, 3, 4, 9, 10, 11, 12, 17, 20};
	int n = a.size();
	int k=4;
	
	cout<< MinRemov(a,n,k) <<endl;
    
	return 0;
}
