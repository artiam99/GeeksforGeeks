#include<bits/stdc++.h>
using namespace std;
pair<int,int> Rec(vector<int> &a,int n,int k,vector<vector<pair<int,int>>> &dp)
{
	if(n == 0 || k == 0 || n < k) return {0,0};
	
	if(dp[n][k].first != -1)  return dp[n][k];
	
	int pw2  = 0 , pw5 = 0;
	
	int x = a[n-1];
	
	while(x % 2 == 0)
	{
		pw2++;
		
		x /= 2;
	}
	
	while(x % 5 == 0)
	{
		pw5++;
		
		x /= 5;
	}
	
	pair<int,int> d1 = Rec(a,n-1,k-1,dp);
	
	pair<int,int> d2 = Rec(a,n-1,k,dp);
	
	if( min(d1.first + pw2 , d1.second + pw5) >= min(d2.first , d2.second) )
	return dp[n][k] = {d1.first + pw2 , d1.second + pw5};
	
	return dp[n][k] = d2;
}
int MaxTrailingZero(vector<int> &a,int n,int k)
{
	vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(k+1,{-1,-1}));
	
	pair<int,int> p = Rec(a,n,k,dp);
		
	return min(p.first , p.second);
}
signed main()
{
	vector<int> a = {15, 16, 3, 25, 9};
	int n = a.size();
	
	int k = 3;
	
	cout<< MaxTrailingZero(a,n,k) <<endl;
	
	return 0;
}
