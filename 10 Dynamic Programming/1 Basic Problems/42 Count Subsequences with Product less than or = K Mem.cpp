#include<bits/stdc++.h>
using namespace std;
int Rec(int ind,vector<int> &a,int n,int k,vector<vector<int>> &dp)
{
	if(ind==n)
	return 1;
	
	if(dp[ind][k] != -1)
	return dp[ind][k];
	
	return dp[ind][k] = Rec(ind+1,a,n,k,dp) + ( (a[ind] <= k) ? Rec(ind+1,a,n,k/a[ind],dp) : 0 );
}
int SubSecProdlessthanK(vector<int> &a,int n,int k)
{
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	
	return Rec(0,a,n,k,dp) - 1;
}
signed main()
{
	vector<int> a = {4, 7, 8, 2};
	int n=a.size();
	int k=50;
    
    cout<< SubSecProdlessthanK(a,n,k) <<endl;
    
	return 0;
}
