#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int l,int r,vector<vector<int>> &dp)
{
	if(l > r)  return 0;
	
	if(dp[l][r] != -1)  return dp[l][r];
	
	int ans = INT_MAX;
	
	for(int i = l ; i <= r ; i++)
	ans = min(ans , Rec(a,l,i-1,dp) + Rec(a,i+1,r,dp) + a[l-1] * a[i] * a[r+1]);
	
	return dp[l][r] = ans;
}
int MinMultiplication(vector<int> &a,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	return Rec(a,1,n-2,dp);
}
signed main()
{
	vector<int> a = {40 , 20 , 30 , 10 , 30};
	int n = a.size();
	
	cout<< MinMultiplication(a,n) <<endl;
    
	return 0;
}
