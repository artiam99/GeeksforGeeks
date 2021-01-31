#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n ,vector<int> &b,int m,int i,int j,vector<vector<int>> &dp)
{
	if(j == m)  return 0;
	
	if(i == n)  return INT_MIN;
	
	if(dp[i][j] != -1)  return dp[i][j];
	
	return dp[i][j] = max( a[i]*b[j] + Rec(a,n,b,m,i+1,j+1,dp) , Rec(a,n,b,m,i+1,j,dp));
}
int MaxDotProd(vector<int> &a,int n,vector<int> &b,int m)
{
	vector<vector<int>> dp(n,vector<int>(m,-1));
	
	return Rec(a,n,b,m,0,0,dp);
}
signed main()
{
	vector<int> a = {2, 3, 1, 7, 8};
	int n = a.size();
	
	vector<int> b = {3, 6, 7};
	int m = b.size();
	
	cout<< MaxDotProd(a,n,b,m) <<endl;
    
	return 0;
}
