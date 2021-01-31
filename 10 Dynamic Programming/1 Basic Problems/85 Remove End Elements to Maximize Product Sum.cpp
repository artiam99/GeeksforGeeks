#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int l,int r,int curr,vector<vector<int>> &dp)
{
	if(l==r)
	return curr + a[l] * a.size();

	
	if(dp[l][r] != -1)  return dp[l][r];
	
	return dp[l][r] = max( Rec(a, l+1 , r , curr + a[l] * (a.size() - (r-l)) , dp) , Rec(a , l , r-1 , curr + a[r] * (a.size() - (r-l)) , dp));
}
int MaximumSumProduct(vector<int> &a,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	return Rec(a,0,n-1,0,dp);
}
signed main()
{
	vector<int> a = { 1, 3, 1, 5, 2 };
	int n = a.size();
	
	cout<< MaximumSumProduct(a,n) <<endl;
	
	return 0;
}
